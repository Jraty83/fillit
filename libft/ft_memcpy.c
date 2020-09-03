/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 15:50:36 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/17 19:07:58 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *dest_ptr;
	unsigned char *src_ptr;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	while (n)
	{
		*dest_ptr++ = *src_ptr++;
		n--;
	}
	return (dest);
}
