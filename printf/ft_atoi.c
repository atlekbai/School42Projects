/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:31:44 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/25 14:26:04 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	long long int	res;
	long long int	b;

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
		res = res * 10 + (long long int)str[i++] - 48;
	if (res < 0)
	{
		if (b == -1)
			return (0);
		return (-1);
	}
	return ((int)res * (int)b);
}
