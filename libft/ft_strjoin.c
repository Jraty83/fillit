/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 19:13:41 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/29 13:20:33 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	str_len;
	char	*new_str;

	str_len = ft_strlen(s1);
	str_len += ft_strlen(s2);
	if (!(new_str = (char *)malloc(sizeof(char) * (str_len + 1))))
		return (NULL);
	while (*s1 || *s2)
		if (*s1)
			*new_str++ = *s1++;
		else
			*new_str++ = *s2++;
	*new_str = '\0';
	return (new_str - str_len);
}
