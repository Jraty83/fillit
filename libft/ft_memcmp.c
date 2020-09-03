/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:02:03 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/21 21:02:04 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *string1;
	unsigned char *string2;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (n)
	{
		if (*string1 != *string2)
			return (*string1 - *string2);
		n--;
		if (!n)
			break ;
		string1++;
		string2++;
	}
	return (0);
}
