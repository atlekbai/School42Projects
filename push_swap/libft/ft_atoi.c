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

static void	ft_exit(void)
{
	ft_printf("Error\n");
	exit(0);
}

int			ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	b;

	i = 0;
	b = 1;
	res = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\v' || str[i] == '\n') && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			b = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && res >= 0)
		res = res * 10 + (int)str[i++] - 48;
	if (res < 0)
	{
		if (b == -1)
			ft_exit();
		ft_exit();
	}
	return ((int)res * (int)b);
}
