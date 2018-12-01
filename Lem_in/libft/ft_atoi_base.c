/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:29:43 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/25 15:59:33 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_base(char c)
{
	int n;

	if (c >= '0' && c <= '9')
		n = c - 48;
	else if (c >= 'a' && c <= 'z')
		n = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		n = c - 'A' + 10;
	else
		n = -1;
	return (n);
}

int			ft_atoi_base(char const *str, int base)
{
	long long int	res;
	long long int	num;
	int				i;

	res = 1;
	num = 0;
	i = 0;
	while (str[i] <= 32 && str[i] != '\e')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			res = -1;
		i++;
	}
	while (get_base(str[i]) >= 0 && get_base(str[i]) <= base && num >= 0)
		num = num * base + (long long int)get_base(str[i++]);
	if (num < 0)
	{
		if (res == -1)
			return (0);
		return (-1);
	}
	return ((int)num * (int)res);
}
