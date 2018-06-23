/*
** EPITECH PROJECT, 2018
** dante
** File description:
** dante
*/

#ifndef		DANTE_H_
#define		DANTE_H_

/*
** structure for queue
** contain coordate of the queuing part
** of the 2Darray
*/
typedef	struct	s_queue
{
	int	x;
	int	y;
	struct	s_queue *next;
}t_queue;

typedef struct	s_map
{
	int	height;
	int	width;
	char	**map;
	char	done;
}t_map;

/*
** src files
*/
char	**create_map(int x, int y);
int	generate_random(int lower, int upper);
void	push(t_queue **head, int x, int y);
void	delete_node(t_queue **head);
void	destroy_queue(t_queue **head);
void	destroy_map(char **map);
int     check_surround(t_queue *prev, t_map *map);
int	add_node(t_queue *prev, t_map *map, int *x, int *y);
void	modify_map(t_map *map, int x, int y);
void	small_maze_generation(int x, int y);

#endif		/*!DANTE_H_*/
