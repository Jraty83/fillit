/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 16:26:35 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/01 10:24:47 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	char			*str_return;
	unsigned int	i;

	i = 0;
	if (!(new_str = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	str_return = new_str;
	while (*s)
		*new_str++ = f(i++, *s++);
	*new_str = '\0';
	return (str_return);
}
