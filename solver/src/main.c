/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "dante.h"

void	destroy_all(t_map *map, t_queue **prev)
{
	free(map->map);
	destroy_queue(prev);
	free(map);
	exit(0);
}

void	final_map_modification(t_map *map, t_queue **prev)
{
	for (int i = 0; map->map[i]; i++) {
		for (int j = 0; map->map[i][j]; j++)
			(map->map[i][j] == 'o') ? (map->map[i][j] = '*') : 0;
	}
	while ((*prev) != NULL) {
		map->map[(*prev)->y][(*prev)->x] = 'o';
		delete_node(prev);
	}
}

void	end_condition(t_map *map, t_queue **prev)
{
	if (*prev == NULL || ((*prev)->x == 0 && (*prev)->y == 0)) {
		dprintf(2, "Error: no end\n");
		no_end_destruct(map->map);
		destroy_all(map, prev);
		exit(0);
	}
	if ((*prev)->x == (map->width - 2)
	    && (*prev)->y == (map->height - 1)) {
		final_map_modification(map, prev);
		for (int i  = 0; map->map[i]; i++) {
			printf("%s", map->map[i]);
			free(map->map[i]);
		}
		destroy_all(map, prev);
	}
}

void	deep_first_solving(const char *name)
{
	t_map	*map = create_tab(name);
	t_queue	*prev = NULL;
	int	end = 1;
	int	new_x = 0;
	int	new_y = 0;

	push(&prev, 0, 0);
	map->map[0][0] = 'o';
	while (end == 1) {
		if (check_surround(prev, map) >= 4) {
			delete_node(&prev);
		} else {
			end = add_node(prev, map, &new_x, &new_y);
			push(&prev, new_x, new_y);
		}
		end_condition(map, &prev);
	}
}

int main(int ac, char **av)
{
	struct stat	st;

	if (ac < 2) {
		dprintf(2, "Error; invalide argument number\n");
		return (84);
	}
	lstat(av[1], &st);
	if(S_ISDIR(st.st_mode)) {
		dprintf(2, "Error: %s is a directory\n", av[1]);
		return (84);
	}
		deep_first_solving(av[1]);
	return (0);
}
