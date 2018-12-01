/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:55:58 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/12/12 17:33:26 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*printing(int n, char *d, int sign, int k)
{
	d[k] = '\0';
	if (n == 0)
		d[0] = 48;
	if (sign == 1)
	{
		sign = 0;
		d[0] = '-';
		d[--k] = (char)((n % 10) + 48 + 1);
		n = n / 10;
	}
	while (n > 0)
	{
		d[--k] = (char)((n % 10) + 48);
		n = n / 10;
	}
	return (d);
}

char		*ft_itoa(int n)
{
	int		k;
	int		sign;
	char	*d;
	int		i;

	k = 0;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = (-n) - 1;
		k++;
	}
	i = n;
	if (i == 0)
		k++;
	while (i > 0)
	{
		i = i / 10;
		k++;
	}
	if (!(d = (char *)malloc(sizeof(char) * k + 1)))
		return (NULL);
	return (printing(n, d, sign, k));
}
