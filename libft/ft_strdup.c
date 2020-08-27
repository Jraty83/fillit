/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:26:50 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/19 19:34:43 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	string_len;
	char	*duplicate;
	char	*ptr_duplicate;

	string_len = ft_strlen(s) + 1;
	duplicate = (char *)malloc(sizeof(char) * string_len);
	if (!duplicate)
		return (NULL);
	ptr_duplicate = duplicate;
	while (string_len--)
		*duplicate++ = *s++;
	return (ptr_duplicate);
}
