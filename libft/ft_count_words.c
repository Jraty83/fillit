/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 03:48:28 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/16 03:59:15 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_words(char const *s, char white_space)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s == white_space)
			while (*s && *s == white_space)
				s++;
		else
		{
			i++;
			while (*s && *s != white_space)
				s++;
		}
	}
	return (i);
}
