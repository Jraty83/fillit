/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 00:18:54 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/23 01:44:18 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_element;

	new_element = (t_list *)malloc(sizeof(t_list));
	if (!new_element)
		return (NULL);
	if (!content)
	{
		new_element->content = NULL;
		new_element->content_size = 0;
	}
	else
	{
		if (!(new_element->content = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(new_element->content, content, content_size); 
		new_element->content_size = content_size;
	}
	new_element->next = NULL;
	return (new_element);
}
