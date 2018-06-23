/*
** EPITECH PROJECT, 2018
** select_rand
** File description:
** select
*/

#include <stdlib.h>
#include "dante.h"

int	check_surround(t_queue *prev, t_map *map)
{
	int	walls = 0;
	int	x = prev->x;
	int	y = prev->y;
	int	height = map->height - 1;
	int	weight = map->width - 1;

	if ((x - 1) < 0 || map->map[y][x - 1] == 'o'
	|| map->map[y][x - 1] == 'X')
		walls += 1;
	if ((y - 1) < 0 || map->map[y - 1][x] == 'o'
	|| map->map[y - 1][x] == 'X')
		walls += 1;
	if ((x + 2) > weight || map->map[y][x + 1] == 'o'
	|| map->map[y][x + 1] == 'X')
		walls += 1;
	if ((y + 1) > height || map->map[y + 1][x] == 'o'
	|| map->map[y + 1][x] == 'X')
		walls += 1;
	return (walls);
}

static void	affect_new_coord(char rand, int *x, int *y)
{
	switch (rand) {
	case 1:
		*x = 1;
		*y = 0;
		break;
	case 2:
		*x = 0;
		*y = 1;
		break;
	case 3:
		*x = -1;
		*y = 0;
		break;
	case 4:
		*x = 0;
		*y = -1;
		break;
	}
}

int	add_node(t_queue *prev, t_map *map, int *new_x, int *new_y)
{
	int	x = 0;
	int	y = 0;
	char	m_rand = 1;

	do {
		affect_new_coord(m_rand, &x, &y);
		*new_x = prev->x + x;
		*new_y = prev->y + y;
		m_rand += 1;
	} while (((*new_x < 0 || *new_y < 0)
		|| (*new_x > (map->width - 2)
		|| *new_y > (map->height - 1)))
		|| map->map[*new_y][*new_x] == 'X'
		|| map->map[*new_y][*new_x] == 'o');
	map->map[*new_y][*new_x] = 'o';
	return (1);
}
