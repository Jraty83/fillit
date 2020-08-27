/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:28:02 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/19 17:55:47 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char *dest_ptr;
	unsigned char *src_ptr;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	if (src_ptr < dest_ptr)
	{
		src_ptr += len;
		dest_ptr += len;
		while (len)
		{
			*--dest_ptr = *--src_ptr;
			len--;
		}
	}
	else
		ft_memcpy(dest_ptr, src_ptr, len);
	return (dest);
}
