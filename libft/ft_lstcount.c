/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:49:54 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/19 19:35:12 by ekinnune         ###   ########.fr       */
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
