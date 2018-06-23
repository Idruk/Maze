/*
** EPITECH PROJECT, 2018
** mod
** File description:
** mod
*/

#include "dante.h"

static void	modify_y_axis(t_map *map, int x, int y)
{
	int i;

	if ((y % 2) == 0) {
		for (i = 0; i < x; i++)
			map->map[y - 1][i] = 'X';
		map->map[y - 1][i - 1] = '*';
		map->height -= 1;
	}
}

static void	modify_x_axis(t_map *map, int x, int y)
{
	int i;

	if ((x % 2) == 0) {
		for (i = 0; i < y; i++)
			map->map[i][x - 1] = 'X';
		map->width -= 1;
		map->map[i - 1][x - 1] = '*';
	}
}

void	modify_map(t_map *map, int x, int y)
{
	modify_x_axis(map, x, y);
	modify_y_axis(map, x, y);
	if ((x % 2) == 0 && (y % 2) == 0)
		map->map[map->height][map->width - 1] = '*';
}
