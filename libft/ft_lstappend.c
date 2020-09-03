/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 04:27:14 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/16 04:48:58 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list *front, t_list *add)
{
	t_list *walker;

	if (!add)
		return ;
	if (front)
	{
		walker = front;
		while (walker->next)
			walker = walker->next;
		walker->next = add;
	}
	else
		front = add;
}
