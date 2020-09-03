/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 01:22:02 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/17 18:38:03 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	back_track_cheat;
	size_t	back_track_save;

	back_track_cheat = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[back_track_cheat])
	{
		i = 0;
		back_track_save = back_track_cheat;
		while (s1[back_track_cheat] == s2[i])
		{
			i++;
			back_track_cheat++;
			if (!s2[i])
				return ((char *)(s1 + back_track_save));
		}
		back_track_cheat = ++back_track_save;
	}
	return (NULL);
}
