/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 19:06:20 by ekinnune          #+#    #+#             */
/*   Updated: 2020/09/03 12:00:10 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_tetro_count(t_tetro *struct_tetro)
{
	size_t count;

	count = 0;
	while (struct_tetro->prev)
	{
		struct_tetro = struct_tetro->prev;
	}
	while (struct_tetro)
	{
		struct_tetro = struct_tetro->next;
		count++;
	}
	return (count);
}

void	ft_set_coordinates(t_tetro **element)
{
	char	*str;
	int		y;
	int		x;
	int		i;
	int		block_count;

	y = 0;
	x = 0;
	i = 0;
	block_count = 0;
	str = (*element)->raw;
	while (str[i])
	{
		if (str[i] == '#')
		{
			x = (i - y) % 4;
			(*element)->x[block_count] = x;
			(*element)->y[block_count] = y;
			block_count++;
		}
		if (str[i] == '\n')
			y++;
		i++;
	}
}

t_tetro	*ft_new_tetro(char *tetro_string, t_tetro *previous, int i)
{
	t_tetro *new;

	if (!(new = (t_tetro *)malloc(sizeof(t_tetro))))
	{
		return (NULL);
	}
	new->letter = i;
	new->raw = tetro_string;
	new->next = NULL;
	ft_set_coordinates(&new);
	if (!previous)
	{
		new->prev = NULL;
	}
	else
	{
		new->prev = previous;
	}
	return (new);
}

t_tetro	*ft_process_raw(char **raw)
{
	t_tetro *head;
	t_tetro	*copy;
	size_t	i;

	i = 0;
	if (!(head = ft_new_tetro(raw[i], NULL, i)))
	{
		return (NULL);
	}
	copy = head;
	while (raw[++i])
	{
		if (!(copy->next = ft_new_tetro(raw[i], copy, i)))
		{
			return (NULL);
		}
		copy = copy->next;
	}
	ft_free2d(raw);
	return (head);
}
