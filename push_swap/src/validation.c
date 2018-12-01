/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 12:17:48 by atlekbai          #+#    #+#             */
/*   Updated: 2018/11/06 12:17:49 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_num(char *str)
{
	char	minus;

	if (*str == '-' && ft_strlen(str) == 1)
		return (0);
	minus = 0;
	while (*str == '-')
	{
		if (*str == '-')
			minus++;
		if (minus > 1)
			return (0);
		str++;
	}
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != 0)
		return (0);
	return (1);
}

int		check_array(int *arr, int len)
{
	int	i;

	i = 0;
	while (++i < len)
		if (arr[i - 1] == arr[i])
			return (0);
	return (1);
}

void	ft_exit(void)
{
	ft_printf("Error\n");
	exit(0);
}
