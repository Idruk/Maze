/*
** EPITECH PROJECT, 2018
** read
** File description:
** read
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dante.h"

static void	push_line(t_file **file, char *line)
{
	t_line	*new = malloc(sizeof(t_line));

	if (!new)
		exit(84);
	new->line = malloc(sizeof(char) * (strlen(line) + 1));
	if (!new->line)
		exit(84);
	new->line = strcpy(new->line, line);
	if ((*file)->head == NULL) {
		(*file)->head = new;
		(*file)->head->next = NULL;
		return;
	}
	new->next = (*file)->head;
	(*file)->head = new;
	(*file)->nb += 1;
}

static t_file	*read_map(const char *map)
{
	FILE	*stream;
	char	*line = NULL;
	size_t	len = 0;
	ssize_t	nread;
	t_file	*file = malloc(sizeof(t_file));

	file->head = NULL;
	file->nb = 1;
	stream = fopen(map, "r");
	if (stream == NULL || file == NULL) {
	        dprintf(2, "Error: fopen\n");
		exit(84);
	}
	do {
		nread = getline(&line, &len, stream);
		push_line(&file, line);
	} while (nread != -1);
	free(line);
	fclose(stream);
	return (file);
}

static void	destroy_file(t_file *file)
{
	t_line	*tmp;

	while (file->head != NULL) {
		tmp = file->head;
		free(tmp->line);
		file->head = file->head->next;
		free(tmp);
	}
	free(file);
}

static void	init_tab(t_file *file, t_map *map)
{
	t_line	*tmp = file->head;
	int	error = 0;
	int	i;

	tmp = tmp->next;
	for (i = file->nb - 1; i >= 0; i--) {
		map->map[i] = malloc(sizeof(char) * (strlen(tmp->line) + 1));
		if (map->map[i] == NULL)
			exit(84);
		error = check_error_charactere(tmp->line);
		map->map[i] = strcpy(map->map[i], tmp->line);
		tmp = tmp->next;
	}
	if (error == 1
	|| map->map[file->nb - 1][strlen(map->map[file->nb - 1]) - 1] == '\n')
		destroy_interupted(file, map, file->nb);
	free(tmp);
}

t_map	*create_tab(const char *name)
{
	t_file	*file = read_map(name);
	t_map	*map = malloc(sizeof(t_map));

	map->map = malloc(sizeof(char*) * ((file->nb) + 2));
	if (map->map == NULL)
		exit(84);
	file->nb -= 1;
	init_tab(file, map);
	map->map[file->nb] = NULL;
	map->height = file->nb;
	map->width = strlen(map->map[0]);
	map->done = 1;
	destroy_file(file);
	return (map);
}
