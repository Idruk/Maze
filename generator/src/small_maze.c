/*
** EPITECH PROJECT, 2018
** small_maze
** File description:
** small_maze_generation
*/

#include <stdio.h>

static void	choose_charact(int x, int i, int j)
{
	if (i % 2 == 0) {
		printf("*");
	} else {
		(j != (x - 1)) ? printf("X"): printf("*");
	}
}

void	small_maze_generation(int x, int y)
{
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			choose_charact(x, i, j);
		}
		(i != y - 1) ? printf("\n") : 0;
	}
}
