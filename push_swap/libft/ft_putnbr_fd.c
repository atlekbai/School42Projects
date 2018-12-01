/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:46:44 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/02 20:14:39 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int nb_long;

	nb_long = nb;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb_long *= (-1);
	}
	if (nb_long > 9)
	{
		ft_putnbr_fd(nb_long / 10, fd);
	}
	ft_putchar_fd(48 + nb_long % 10, fd);
}
