/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:21:46 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/17 18:30:43 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t len;
	size_t dest_len;

	dest_len = ft_strlen(dest);
	len = dest_len + ft_strlen(src);
	if (n > ft_strlen(src))
		n = len - dest_len;
	while (n-- > 0)
		dest[dest_len++] = *(src++);
	dest[dest_len] = '\0';
	return (dest);
}
