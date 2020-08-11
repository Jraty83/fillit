/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:32:56 by jraty             #+#    #+#             */
/*   Updated: 2020/08/10 15:55:44 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/jraty/libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdio.h>

int		ft_error(int n)
{
	if (n == 1)
		printf("line lentgh 'x' not 4\n");
	if (n == 2)
		printf("line count 'y' not 4\n");
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
	size_t	tetri;

	l_count = 0;
	l = 0;
	tetri = 0;
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
		printf("\tline [%zu]", l++);
		if (!(*line))
		{
			tetri++;
			printf("\tl is %zu\ttetri count is: %zu", l, tetri);
			if (l != (tetri * 5))
			{
				printf("\n\033[33minvalid file\033[0m\n");
				return (0);
			}
			l_count--; 
		}
		else
		{
			if (ft_strlen(line) == 4)
				printf("\t\033[32mlength OK\033[0m");
			else
			{
				printf("\t\033[31mwrong length\033[0m");
				return (ft_error(1));
			}
			while (line[i])
			{
				if (line[i] == '.' || line[i] == '#')
					c++;
				i++;
			}
			printf(c == ft_strlen(line) ? "\t\033[32mdotorhash OK\033[0m" : "\t\033[31mwrong characters\033[0m");
		}
		free(line);
		printf("\n");
		l_count++;
	}
	printf("\033[33mnumber of lines is: %zu\033[0m\n", l_count);
	printf("\033[33mnumber of tetriminos is: %zu\033[0m\n", tetri);
	close(fd);
	if (fd == -1)
	{
		ft_putstr("close() failed.\n");
		return (0);
	}
	return (0);
}
