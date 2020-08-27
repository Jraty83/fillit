/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 22:15:13 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/17 18:32:13 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_unsigned;
	unsigned char	*s2_unsigned;

	i = 0;
	s1_unsigned = (unsigned char *)s1;
	s2_unsigned = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && s1_unsigned[i])
	{
		if (s1_unsigned[i] - s2_unsigned[i] == 0)
			i++;
		else
			break ;
		if (i == n)
			return (0);
	}
	return (s1_unsigned[i] - s2_unsigned[i]);
}
