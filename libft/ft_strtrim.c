/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:40:06 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/20 12:22:40 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_alloc_trimmed(char const *s, size_t *i)
{
	char	*trimmed;

	while (s[*i])
	{
		if (*i == 0)
		{
			while (*s == ' ' || *s == '\n' || *s == '\t')
				s++;
		}
		if (!s[(*i) + 1])
		{
			while (s[*i] == ' ' || s[*i] == '\n' || s[*i] == '\t')
				(*i)--;
			break ;
		}
		(*i)++;
	}
	if (!(trimmed = (char *)malloc(sizeof(char) * ((*i) + 2))))
		return (NULL);
	return (trimmed);
}

char		*ft_strtrim(char const *s)
{
	char	*trimmed;
	size_t	i;
	size_t	trim_i;

	i = 0;
	trim_i = 0;
	if (!(trimmed = ft_alloc_trimmed(s, &i)))
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (trim_i <= i)
		trimmed[trim_i++] = *s++;
	trimmed[trim_i] = '\0';
	return (trimmed);
}
