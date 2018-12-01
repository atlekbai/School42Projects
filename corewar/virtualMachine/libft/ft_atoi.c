/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:54:45 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/07 12:07:44 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_miss(const char *str)
{
	int i;

	i = 0;
	while (str[i] < 33 || str[i] == 127)
	{
		if (str[i] == '\200')
			return (0);
		if (str[i] == '\e')
			return (0);
		i++;
	}
	if (str[i] == '+' && str[i + 1] == '-')
		return (0);
	if (str[i] == '+')
		i++;
	return (i);
}

static int	ft_realatoi(const char *str, int neg, int i)
{
	unsigned int	res;
	int				longgg;

	res = 0;
	longgg = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		if (longgg == 18 && neg == 0)
			return (-1);
		if (longgg == 18 && neg == 1)
			return (0);
		if ((res * 10 + (str[i] - 48)) > 0)
			res = res * 10 + (str[i] - 48);
		i++;
		longgg++;
	}
	return (res);
}

int			ft_atoi(const char *str)
{
	unsigned int	res;
	int				neg;
	int				i;

	neg = 0;
	i = ft_miss(str);
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	while (str[i] == '0')
		i++;
	res = ft_realatoi(str, neg, i);
	if (neg == 1)
		return (res = -res);
	return (res);
}
