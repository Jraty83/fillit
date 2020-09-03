/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 20:10:33 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/20 17:32:11 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t		i;

	i = 0;
	while (*s != c && *s)
	{
		i++;
		s++;
	}
	return (i);
}

static char		**ft_make_2d(const char *s, char **s_2d, char c)
{
	size_t		i;
	size_t		j;
	size_t		word_size;

	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			i = 0;
			word_size = ft_count_word(s, c);
			if (!(s_2d[j] = (char *)malloc(sizeof(char) * (word_size + 1))))
				return (ft_free2d(s_2d));
			while (*s != c && *s)
				s_2d[j][i++] = *s++;
			s_2d[j++][i] = '\0';
		}
		else
			s++;
	}
	s_2d[j] = NULL;
	return (s_2d);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		word_count;
	const char	*s_cpy;
	char		**s_2d;

	s_cpy = (char *)s;
	word_count = 0;
	while (*s_cpy)
	{
		if (*s_cpy != c)
		{
			s_cpy += ft_count_word(s_cpy, c);
			word_count++;
		}
		s_cpy++;
	}
	s_2d = (char **)malloc(sizeof(char *) * ++word_count);
	if (!s_2d)
		return (NULL);
	return (ft_make_2d(s, s_2d, c));
}
