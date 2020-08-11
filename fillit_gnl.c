/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:32:56 by jraty             #+#    #+#             */
/*   Updated: 2020/08/10 12:48:08 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/jraty/libft/libft.h"
#include "fillit.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc < 2)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed.\n");
		return (0);
	}
	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr(line);
		free(line);
		ft_putstr("\n");
	}
	close(fd);
	if (fd == -1)
	{
		ft_putstr("close() failed.\n");
		return (0);
	}
	return (0);
}
