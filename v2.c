/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:32:56 by jraty             #+#    #+#             */
/*   Updated: 2020/08/13 13:26:47 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_error(int n)
{
	printf("\033[01;31m=====================NOT=VALID======================\033[0m\n");
	if (n == 0)
		printf("\033[31musage: ./fillit target_file\033[0m\n");
	if (n == 1)
		printf("\033[31mopen() failed.\033[0m\n");
	if (n == 2)
		printf("\t\033[31mline lentgh 'x' not 4\033[0m\n");
	if (n == 3)
		printf("\t\033[31mline count 'y' not 4\033[0m\n");
	if (n == 4)
		printf("\t\033[31mwrong characters\033[0m\n");
	if (n == 6)
		printf("\033[31mwrong amount of hashes\033[0m\n");
	if (n == 7)
		printf("\033[31mhashes don't join\033[0m\n");
	if (n == 8)
		printf("\033[31mdoesn't end with a single newline.\033[0m\n");
	if (n == 9)
		printf("\033[31mclose() failed.\033[0m\n");
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd = 4;

	if (argc != 2)
		return (ft_error(0));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error(1));
// CHECKER 1
	char	*line;
	size_t	i;
	size_t	l;
	
	l = 0;
	while (get_next_line(fd, &line) == 1)
	{
		l++;
		printf("%s\tline [%zu]", line, l);
		if (!(*line))
		{
			if (l % 5 != 0)
				return (ft_error(3));
		}
		else
		{
			if (ft_strlen(line) == 4)
				printf("\t\033[32mlength OK\033[0m");
			else
				return (ft_error(2));
			i = 0;
			while (line[i])
			{
				if (line[i] != '.' && line[i] != '#')
					return (ft_error(4));
				i++;
			}
			if (i == ft_strlen(line))
				printf("\t\033[32mdotorhash OK\033[0m");
		}
		free(line);
		printf("\n");
	}
	if ((l + 1) % 5 != 0)
		return (ft_error(8));
	if (close(fd) == -1)
		return (ft_error(9));
// CHECKER 2 (READ IT AGAIN && BUF_SIZE NEEDS TO BE 21!)
//#undef BUF_SIZE
//#define BUF_SIZE 21
	char	buf[BUF_SIZE + 1];
	int		ret;
	int		hash;
//	int		fd;
//	size_t	i;
	
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error(1));
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		i = 0;
		hash = 0;
		while (buf[i])
		{
			if (buf[i] == '#')
			{
				if (buf[i - 5] != '#' && buf[i + 5] != '#' && buf[i + 1] != '#' && buf[i - 1] != '#')
					return (ft_error(7));
				hash++;
			}
			i++;
		}
		if (hash != 4)
			return (ft_error(6));
	}
	if (!(buf[i - 1] == 10 && buf[i] == 0))
		return (ft_error(8));
	if (close(fd) == -1)
		return (ft_error(9));
	printf("\033[01;33m=====================VALID=FILE=====================\033[0m\n");
	printf("\033[33mnumber of lines is: %zu               BUF_SIZE is: %d\033[0m\n", l, BUF_SIZE);
//	while (1);
	return (0);
}
