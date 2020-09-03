/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 01:51:47 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/21 18:32:38 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	back_track_cheat;
	size_t	back_track_save;
	size_t	temp_len;

	back_track_cheat = 0;
	temp_len = len;
	if (!*s2)
		return ((char *)s1);
	while (len && temp_len && s1[back_track_cheat])
	{
		i = 0;
		temp_len = len;
		back_track_save = back_track_cheat;
		while (s1[back_track_cheat++] == s2[i++] && temp_len)
		{
			if (!s2[i])
				return ((char *)(s1 + back_track_save));
			temp_len--;
		}
		len--;
		back_track_cheat = ++back_track_save;
	}
	return (NULL);
}
