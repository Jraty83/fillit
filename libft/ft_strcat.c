/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:34:02 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/17 18:16:36 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t len;
	size_t dest_len;

	dest_len = ft_strlen(dest);
	len = dest_len + ft_strlen(src);
	while (dest_len < len)
		dest[dest_len++] = *(src++);
	dest[dest_len] = '\0';
	return (dest);
}
