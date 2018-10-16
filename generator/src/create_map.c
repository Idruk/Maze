#include <string.h>
#include <stdlib.h>
#include "dante.h"

/*
** free the map
*/
void	destroy_map(char **map)
{
	int	i;

	for (i = 0; map[i]; i++)
		free(map[i]);
	free(map);
}

static char	*create_wall(int x)
{
	char	*tmp = malloc(sizeof(char) * (x + 1));
	int	j;

	for (j = 0; j < x; j++) {
		tmp[j] = 'X';
	}
	tmp[j] = '\0';
	return (tmp);
}

static char	*create_inter_wall(int x)
{
	char	*tmp = malloc(sizeof(char) * (x + 1));
	int	j;

	for (j = 0; j < x; j++) {
		if (j % 2)
			tmp[j] = '.';
		else
			tmp[j] = 'X';
	}
	tmp[j] = '\0';
	return (tmp);
}

/*
** create a char** wich contain the map
*/
char	**create_map(int x, int y)
{
	char	**map = malloc(sizeof(char*) * (y + 1));
	char	*tmp = create_wall(x);
	char	*tmp2 = create_inter_wall(x);
	int	i;

	for (i = 0; i < y; i++) {
		map[i] = malloc(sizeof(char) * (x + 2));
		if (i % 2 == 0)
			map[i] = strcpy(map[i], tmp);
		else
			map[i] = strcpy(map[i], tmp2);
	}
	map[i] = NULL;
	free(tmp);
	free(tmp2);
	return (map);
}
