/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_makers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:30:41 by ekinnune          #+#    #+#             */
/*   Updated: 2020/09/03 11:48:40 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_single_shapes(char *f_content)
{
	char	**shape_list;
	int		shape_count;
	int		i;
	int		sub_i;

	i = 0;
	sub_i = 0;
	shape_count = ft_count_words(f_content, '\n') / 4;
	if (!(shape_list = (char **)malloc(sizeof(char *) * shape_count + 1)))
	{
		return (NULL);
	}
	while (i < shape_count)
	{
		if (!(shape_list[i] = ft_strsub(f_content, sub_i, 20)))
		{
			ft_free2d(shape_list);
			return (NULL);
		}
		i++;
		sub_i += 21;
	}
	shape_list[i] = 0;
	free(f_content);
	return (shape_list);
}

char	**ft_file_save(int fd, char **argv)
{
	size_t	f_size;
	char	*file;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		write(2, "error\n", 6);
		return (NULL);
	}
	f_size = ft_file_size(fd);
	if (!(file = ft_strnew(f_size)))
	{
		return (NULL);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		write(2, "error\n", 6);
		return (NULL);
	}
	if (read(fd, file, f_size) == -1)
	{
		write(2, "error\n", 6);
		return (NULL);
	}
	return (ft_single_shapes(file));
}

int		ft_error(void)
{
	ft_putstr("error\n");
	return (0);
}

int		ft_usage(void)
{
	ft_putstr("usage: ./fillit source_file\n");
	return (0);
}
