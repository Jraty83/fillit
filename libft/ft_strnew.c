/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:57:34 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/17 18:33:08 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_str;
	char	*new_str_ptr;
	size_t	i;

	i = 0;
	new_str = (char *)malloc(size + 1);
	if (!new_str)
		return (NULL);
	new_str_ptr = new_str;
	while (i++ <= size)
		*new_str++ = '\0';
	return (new_str_ptr);
}
