/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 21:16:40 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/17 18:28:12 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	start_size;

	start_size = size;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	while (*dst && size)
	{
		dst++;
		size--;
	}
	if (size == 0)
		return (start_size + src_len);
	while (*src && size - 1)
	{
		*dst++ = *src++;
		size--;
	}
	*dst = '\0';
	return (dst_len + src_len);
}
