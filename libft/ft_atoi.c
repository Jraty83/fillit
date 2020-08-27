/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 17:23:39 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/21 20:16:01 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	long int	value;
	int			sign;

	sign = 1;
	value = 0;
	while (*nptr == ' ' || *nptr == '\r' || *nptr == '\t'
			|| *nptr == '\n' || *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		value *= 10;
		value += *nptr - '0';
		nptr++;
	}
	return (value * sign);
}
