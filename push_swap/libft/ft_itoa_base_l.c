/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:34:21 by hdanylev          #+#    #+#             */
/*   Updated: 2018/02/16 19:34:48 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_size(long n, int base)
{
	int size;

	size = 0;
	if (n == 0)
		size++;
	while (n != 0)
	{
		n /= base;
		size++;
	}
	return (size);
}

char			*ft_itoa_base_l(long n, int base)
{
	int						size;
	int						neg;
	char					*str;
	unsigned long long int	num;

	num = n;
	neg = 0;
	if (base == 10 && n < 0)
	{
		num = n * (-1);
		neg = 1;
	}
	size = ft_size(n, base);
	if (!(str = (char*)malloc(sizeof(char) * (size + neg + 1))))
		return (NULL);
	str[(size--) + neg] = '\0';
	while (size + neg >= 0)
	{
		str[size + neg] = (num % base) + ((num % base) >= 10 ? 'a' - 10 : '0');
		num = num / base;
		size--;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
