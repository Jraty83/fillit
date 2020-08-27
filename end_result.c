/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_result.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 19:31:53 by ekinnune          #+#    #+#             */
/*   Updated: 2020/08/20 19:31:53 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **ft_abc_grid(t_tetro *tetro)
{
	int	size;
	char **grid;
	int	i;

	i = 0;
	size = GRID_SIZE;
	grid = ft_memalloc(sizeof(char *)* (size + 1));
	grid[size] = NULL;
	while (size)
	{
		size--;
		grid[size] = ft_strnew(GRID_SIZE);
	}
	while (tetro)
	{
		while (i < 4)
		{
			grid[tetro->y[i]][tetro->x[i]] = 'A' + tetro->letter;
			i++;
		}
		i = 0;
		tetro = tetro->next;
	}
	size = 0;
	while (grid[size])
	{
		i = 0;
		while (i < GRID_SIZE)
		{
			if (!grid[size][i])
				grid[size][i] = '.';
			i++;
		}
		size++;
	}
	return (grid);
}

int	ft_judge_grid(int **grid)
{
	int y;
	int x;
	int score;

	y = 0;
	x = 0;
	score = 0;
	while (y < GRID_SIZE)
	{
		x = 0;
		while (x < GRID_SIZE)
		{
			if (grid[y][x] == 0)
				score += y + x;
			x++;
		}
		y++;
	}
	return (score);
}
