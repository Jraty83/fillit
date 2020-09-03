/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 15:41:36 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/01 10:29:44 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *dest_ptr;

	dest_ptr = dest;
	while (n--)
	{
		if (*src)
			*dest++ = *src++;
		else
			*dest++ = '\0';
	}
	return (dest_ptr);
}
