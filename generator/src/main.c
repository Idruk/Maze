/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "dante.h"

t_map	*init_generation(int x, int y, t_queue **prev)
{
	t_map	*new_map = NULL;

	if (x <= 4 || y <= 4) {
		small_maze_generation(x, y);
		delete_node(prev);
		free(new_map);
		exit(0);
	}
	new_map = malloc(sizeof(t_map));
	if (new_map == NULL) {
		dprintf(2, "Error: malloc NULL\n");
		exit(84);
	}
	srand(time(0));
	new_map->done = 0;
	new_map->height = y;
	new_map->width = x;
	new_map->map = create_map(x, y);
	return (new_map);
}

void	display_map(char **map)
{
	int	len;

	for (len = 0; map[len]; len++);
	for (int i = 0; map[i]; i++) {
		printf("%s", map[i]);
		if (i < (len - 1))
			printf("\n");
	}
}

void	end_all(t_map *map, t_queue **queue)
{
	map->map[0][0] = '*';
	map->map[0][1] = '*';
	map->map[map->height - 1][map->width - 1] = '*';
	map->map[map->height - 1][map->width - 2] = '*';
	display_map(map->map);
	destroy_queue(queue);
	destroy_map(map->map);
	free(map);
	exit(0);
}

void	deep_first_generation(int x, int y)
{
	t_map	*map = NULL;
	t_queue	*prev = NULL;
	int	end = 1;
	int	new_x = 0;
	int	new_y = 0;

	push(&prev, 1, 1);
	map = init_generation(x, y, &prev);
	map->map[1][1] = '*';
	while (end == 1) {
		if (prev->x == 1 && prev->y == 1 && map->done == 1)
			end_all(map, &prev);
		if (check_surround(prev, map) >= 4) {
			delete_node(&prev);
		} else {
			end = add_node(prev, map, &new_x, &new_y);
			push(&prev, new_x, new_y);
		}
		map->done = 1;
	}
}

int main(int ac, char **av)
{
	if (ac < 3 || ac > 4)
		return (84);
	deep_first_generation(atoi(av[1]), atoi(av[2]));
	return (0);
}
