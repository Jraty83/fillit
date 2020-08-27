/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 15:54:41 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/16 01:17:14 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list_ptr;

	if (alst && del)
	{
		while (*alst)
		{
			list_ptr = (*alst)->next;
			ft_lstdelone(&(*alst), del);
			*alst = list_ptr;
		}
	}
}
