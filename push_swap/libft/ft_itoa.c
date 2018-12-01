/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:37:53 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/06 16:22:22 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_count(long n, int neg)
{
	int i;

	i = 1;
	if (neg == 1)
		i = i + 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(long nb)
{
	int				neg;
	int				i;
	char			*str;

	neg = 0;
	if (nb < 0)
	{
		neg = 1;
		nb *= -1;
	}
	i = ft_count(nb, neg);
	str = ft_strnew(i);
	if (str == NULL)
		return (0);
	while (i-- > 0)
	{
		str[i] = nb % 10 + 48;
		nb = nb / 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
