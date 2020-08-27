/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 15:57:28 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/01 10:38:25 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *new_str;
	char *str_return;

	if (!(new_str = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	str_return = new_str;
	while (*s)
		*new_str++ = f(*s++);
	*new_str = '\0';
	return (str_return);
}
