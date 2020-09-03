/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:49:54 by ekinnune          #+#    #+#             */
/*   Updated: 2020/09/02 23:30:02 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcount(t_list **start)
{
	int		i;
	t_list	*head;

	i = 0;
	head = *start;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}
