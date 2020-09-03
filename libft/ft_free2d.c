/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 16:13:29 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/21 20:09:44 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free2d(char **array_2d)
{
	size_t i;

	i = 0;
	while (array_2d[i])
	{
		free(array_2d[i]);
		i++;
	}
	free(array_2d);
	return (NULL);
}
