#include <stdio.h>
#include <stdlib.h>
#include "dante.h"

void	no_end_destruct(char **map)
{
	for (int i = 0; map[i]; i++) {
		for (int j = 0; map[i][j]; j++)
			map[i][j] == '\n' ? printf("\n")
				: (map[i][j] == 'o' ? printf("*")
				: printf("X"));
		free(map[i]);
	}
}

void	destroy_interupted(t_file *file, t_map *map, int max)
{
	t_line	*tmp;
	int i = file->nb - 1;

	while (file->head != NULL) {
		tmp = file->head;
		free(tmp->line);
		file->head = file->head->next;
		free(tmp);
	}
	free(file);
	for (i = 0; i < max; i++) {
		printf("%s", map->map[i]);
		free(map->map[i]);
	}
	free(map->map);
	free(map);
	exit(0);
}

int	check_error_charactere(char *str)
{
	int i;

	for (i = 0; str[i]; i++) {
		if (!(str[i] == '*' || str[i] == 'X' || str[i] == '\n')) {
		        return (1);;
		}
	}
	return (0);
}
