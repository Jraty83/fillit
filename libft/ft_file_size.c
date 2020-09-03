/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 23:54:25 by jraty             #+#    #+#             */
/*   Updated: 2020/09/02 23:57:31 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_file_size(int fd)
{
	size_t	read_ret;
	size_t	size;
	char	buffer[BUFF_SIZE];

	size = 0;
	read_ret = 0;
	while ((read_ret = read(fd, buffer, BUFF_SIZE)) > 0)
		size += read_ret;
	return (size);
}
