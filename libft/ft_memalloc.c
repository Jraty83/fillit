/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 12:53:18 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/23 01:35:43 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem_area;

	mem_area = (char *)malloc(size);
	if (mem_area)
	{
		ft_bzero(mem_area, size);
	}
	return (mem_area);
}
