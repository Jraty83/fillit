/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:27:36 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/20 13:52:58 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_list;

	if (lst && f)
	{
		new_list = f(lst);
		lst = lst->next;
		while (lst)
		{
			ft_lstappend(new_list, f(lst));
			lst = lst->next;
		}
		return (new_list);
	}
	return (NULL);
}
