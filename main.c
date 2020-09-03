/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 00:24:25 by jraty             #+#    #+#             */
/*   Updated: 2020/09/03 16:54:47 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		**grid;
	int		grid_size;
	t_tetro	*struct_tetro;
	t_tetro *head;

	grid = NULL;
	if (argc != 2)
		return (ft_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error());
	if (ft_checker1(fd) == 0)
		return (ft_error());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error());
	if (ft_checker2(fd) == 0)
		return (ft_error());
	struct_tetro = ft_process_raw(ft_file_save(fd, argv));
	head = struct_tetro;
	grid_size = ft_board_size(ft_tetro_count(struct_tetro));
	grid = ft_bool_2d(grid, 64);
	grid_size = ft_solver(&struct_tetro, grid, grid_size);
	ft_print_grid_abc(head, grid_size);
	return (0);
}
