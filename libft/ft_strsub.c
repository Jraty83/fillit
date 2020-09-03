/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:19:42 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/17 18:38:22 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len--)
		*dest++ = *(s + start + i++);
	*dest = '\0';
	return (dest - i);
}
