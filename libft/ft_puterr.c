/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekinnune <ekinnune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 03:41:20 by ekinnune          #+#    #+#             */
/*   Updated: 2020/07/17 17:34:52 by ekinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puterr(int err_nb)
{
	ft_putstr_fd("\n[ERROR: ", 2);
	ft_putnbr_fd(err_nb, 2);
	ft_putstr_fd("]\n", 2);
}
