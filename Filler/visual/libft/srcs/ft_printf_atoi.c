/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:31:31 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/12/12 17:18:15 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_printf_atoi(char const *str, int pos)
{
	int	num;

	num = 0;
	while ((str[pos] == '0') || (str[pos] == '+') || (str[pos] == '-')
			|| (str[pos] == ' ') || (str[pos] == '#' || str[pos] == '*'))
		pos++;
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		num = num * 10 + str[pos] - '0';
		pos++;
	}
	return (num);
}
