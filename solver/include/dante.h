/*
** EPITECH PROJECT, 2018
** dante
** File description:
** dante
*/

#ifndef		DANTE_H_
#define		DANTE_H_

/*
** temporary structures for file read
*/

typedef struct	s_line
{
	char	*line;
	struct s_line	*next;
}t_line;

typedef	struct	s_file
{
	struct s_line	*head;
	int	nb;
}t_file;

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
void	push(t_queue **head, int x, int y);
void	delete_node(t_queue **head);
void	destroy_queue(t_queue **head);
t_map	*create_tab(const char *map);
int	add_node(t_queue *prev, t_map *map, int *new_x, int *new_y);
int	check_surround(t_queue *prev, t_map *map);
int	check_error_charactere(char *str);
void	no_end_destruct(char **map);
void	destroy_interupted(t_file *file, t_map *map, int max);

#endif		/*!DANTE_H_*/
