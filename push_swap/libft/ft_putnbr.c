/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:46:44 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/04 18:39:41 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr(int nb)
{
	unsigned int nb_long;

	nb_long = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nb_long *= (-1);
	}
	if (nb_long > 9)
	{
		ft_putnbr(nb_long / 10);
	}
	ft_putchar(48 + nb_long % 10);
}
