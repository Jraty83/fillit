/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_makers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:30:41 by ekinnune          #+#    #+#             */
/*   Updated: 2020/08/21 21:33:56 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_file_size(int fd)
{
	size_t	read_ret;
	size_t	size;
	char	ptr_useless[BUFF_SIZE];

	size = 0;
	read_ret = 0;
	while ((read_ret = read(fd, ptr_useless, BUFF_SIZE)) > 0)
			size += read_ret;
	return (size);
}

char	**ft_single_shapes(char *f_content)
{
	char	**shape_list;
	size_t	shape_count;
	size_t	i;
	size_t	sub_i;

	i = 0;
	sub_i = 0;
	shape_count = ft_count_words(f_content, '\n') / 4;
	shape_list = (char **)malloc(sizeof(char *)* shape_count + 1);
	while (i < shape_count)
	{
		shape_list[i++] = ft_strsub(f_content, sub_i, 20);
		sub_i += 21;
	}
	shape_list[i] = NULL;
	return (shape_list);
}

char	**ft_file_save(int fd, char **argv)
{
	size_t	f_size;
	char	*file;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_error(1);
		return (NULL);
	}
	f_size = ft_file_size(fd);
	file = ft_strnew(f_size);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_error(1);
		return (NULL);
	}
	read(fd, file, f_size);
	return (ft_single_shapes(file));
}
