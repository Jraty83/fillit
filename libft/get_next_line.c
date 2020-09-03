/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:03:22 by ekinnune          #+#    #+#             */
/*   Updated: 2020/08/16 14:17:04 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_nl(char **save, char **line, char *temp, size_t len)
{
	if (!(*line = ft_strsub(*save, 0, len)))
		return (-1);
	if (!(temp = ft_strdup(temp + 1)))
		return (-1);
	free(*save);
	*save = temp;
	if (!**save)
		ft_strdel(save);
	return (1);
}

int	ft_to_line(char **save, char **line)
{
	size_t	len;
	char	*temp;

	len = 0;
	temp = *save;
	while (*temp != '\n' && *temp)
	{
		temp++;
		len++;
	}
	if (*temp == '\n')
		return (ft_is_nl(save, line, temp, len));
	else
	{
		if (!(*line = ft_strdup(*save)))
			return (-1);
		ft_strdel(save);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*save[FD_SIZE];
	char		buffer[BUFF_SIZE + 1];
	char		*tmp;
	int			read_count;

	if (fd < 0 || !line)
		return (-1);
	while ((read_count = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		*(buffer + read_count) = '\0';
		if (!save[fd])
			if (!(save[fd] = ft_strnew(0)))
				return (-1);
		tmp = ft_strjoin(save[fd], buffer);
		free(save[fd]);
		save[fd] = tmp;
		if (ft_strchr(save[fd], '\n'))
			break ;
	}
	if (read_count < 0)
		return (-1);
	if (!save[fd] && !read_count)
		return (0);
	return (ft_to_line(&save[fd], line));
}
