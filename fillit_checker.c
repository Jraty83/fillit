/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:32:56 by jraty             #+#    #+#             */
/*   Updated: 2020/08/11 12:13:56 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/jraty/libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>

int		ft_error(int n)
{
	if (n == 1)
		printf("\t\033[31mline lentgh 'x' not 4\033[0m\n");
	if (n == 2)
		printf("\t\033[31mline count 'y' not 4\033[0m\n");
	if (n == 3)
		printf("\t\033[31mwrong characters\033[0m");
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	size_t	l_count;
	size_t	i;
	size_t	c;
	size_t	l;

	l_count = 0;
	l = 0;
	if (argc != 2)
	{
		write(2, "usage: ./fillit target_file\n", 28);
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
		i = 0;
		c = 0;
		printf("%s", line);
		printf("\tline [%zu]", (l++ + 1));
		if (!(*line))
		{
			if (l % 5 != 0)
				return (ft_error(2));
			l_count--; 
		}
		else
		{
			if (ft_strlen(line) == 4)
				printf("\t\033[32mlength OK\033[0m");
			else
				return (ft_error(1));
			while (line[i])
			{
				if (line[i] == '.' || line[i] == '#')
					c++;
				i++;
			}
			if (c == ft_strlen(line))
				printf("\t\033[32mdotorhash OK\033[0m");
			else
				return (ft_error(3));
		}
//		free(line);
		printf("\n");
		l_count++;
	}
	printf("\033[01;33m=====================VALID=FILE=====================\033[0m\n");
	printf("\033[33mnumber of lines is: %zu\033[0m\n", l_count);
	close(fd);
	if (fd == -1)
	{
		ft_putstr("close() failed.\n");
		return (0);
	}
	return (0);
}
