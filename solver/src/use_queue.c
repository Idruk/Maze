/*
** EPITECH PROJECT, 2018
** queue
** File description:
** queue
*/

#include <stdlib.h>
#include "dante.h"

/*
** push a new node in the queue
** affect x and y to the node
*/
void	push(t_queue **head, int x, int y)
{
	t_queue *new = malloc(sizeof(t_queue));

	if (!new)
		exit(84);
	new->x = x;
	new->y = y;
	if (head == NULL) {
		(*head)->next = NULL;
		*head = new;
		return;
	}
	new->next = (*head);
	(*head) = new;
}

/*
** delete the first node of the queue
*/
void	delete_node(t_queue **head)
{
	t_queue *temp;

	if (*head != NULL) {
		temp = *head;
		(*head) = (*head)->next;
		free(temp);
	}
}
/*
** delete the whole queue
*/

void	destroy_queue(t_queue **head)
{
	while ((*head) != NULL)
		delete_node(head);
}
