#include <stdlib.h>
#include "dante.h"

int	check_surround(t_queue *prev, t_map *map)
{
	int	walls = 0;
	int	x = prev->x;
	int	y = prev->y;
	int	height = map->height - 1;
	int	weight = map->width - 1;

	if ((x - 2) < 0 || map->map[y][x - 2] == '*')
		walls += 1;
	if ((y - 2) < 0 || map->map[y - 2][x] == '*')
		walls += 1;
	if ((x + 2) > weight || map->map[y][x + 2] == '*')
		walls += 1;
	if ((y + 2) > height || map->map[y + 2][x] == '*')
		walls += 1;
	return (walls);
}

static void	remove_wall(char **tab, char rand, int x, int y)
{
	switch (rand) {
	case 1:
		tab[y][x - 1] = '*';
		break;
	case 2:
		tab[y - 1][x] = '*';
		break;
	case 4:
		tab[y][x + 1] = '*';
		break;
	case 8:
		tab[y + 1][x] = '*';
		break;
	}
}

static void	affect_new_coord(char rand, int *x, int *y)
{
	switch (rand) {
	case 1:
		*x = 2;
		*y = 0;
		break;
	case 2:
		*x = 0;
		*y = 2;
		break;
	case 4:
		*x = -2;
		*y = 0;
		break;
	case 8:
		*x = 0;
		*y = -2;
		break;
	}
}

int	add_node(t_queue *prev, t_map *map, int *new_x, int *new_y)
{
	int	x = 0;
	int	y = 0;
	char	m_rand;

	do {
		m_rand = (1 << (rand() % 4));
		affect_new_coord(m_rand, &x, &y);
		*new_x = prev->x + x;
		*new_y = prev->y + y;
	} while (((*new_x < 0 || *new_y < 0)
		|| (*new_x > (map->width - 1)
		|| *new_y > (map->height - 1)))
		|| map->map[*new_y][*new_x] == '*');
	map->map[*new_y][*new_x] = '*';
	remove_wall(map->map, m_rand, *new_x, *new_y);
	return (1);
}
