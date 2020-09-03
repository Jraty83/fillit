/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:47:05 by ekinnune          #+#    #+#             */
/*   Updated: 2020/09/03 09:47:51 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**ft_flip_grid(t_tetro *tetro, int **grid)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[tetro->y[i]][tetro->x[i]] == 0)
		{
			grid[tetro->y[i]][tetro->x[i]] = 1;
		}
		else
		{
			grid[tetro->y[i]][tetro->x[i]] = 0;
		}
		i++;
	}
	return (grid);
}

int		**ft_bool_2d(int **grid, int size)
{
	int grid_size;

	grid_size = size;
	if (!(grid = ft_memalloc(sizeof(int *) * (grid_size + 1))))
	{
		return (NULL);
	}
	grid[size] = NULL;
	while (size)
	{
		size--;
		if (!(grid[size] = ft_memalloc(sizeof(int) * grid_size)))
		{
			free(grid);
			return (NULL);
		}
	}
	return (grid);
}

int		ft_board_size(int nb)
{
	int		sq;

	nb *= 4;
	if (nb == 0 || nb == 1)
		return (nb);
	sq = 1;
	while ((sq * sq) <= nb)
	{
		if ((sq * sq) == nb)
			return (sq);
		sq += 1;
	}
	return (sq);
}
