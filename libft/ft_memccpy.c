/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:05:09 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/16 01:17:24 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *dest_ptr;
	unsigned char *src_ptr;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	if (dest && src)
	{
		while (n)
		{
			*dest_ptr++ = *src_ptr++;
			if (*(src_ptr - 1) == (unsigned char)c)
				return (dest_ptr);
			n--;
		}
	}
	return (NULL);
}
