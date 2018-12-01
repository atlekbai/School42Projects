/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:54:17 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/22 20:47:02 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_len(int n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		nb_len;
	int		n1;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nb_len = ft_nb_len(n);
	n1 = n;
	if (n < 0)
	{
		n1 = -n;
		nb_len++;
	}
	res = ft_strnew(nb_len);
	if (!res)
		return (NULL);
	res[--nb_len] = n1 % 10 + '0';
	while (n1 /= 10)
		res[--nb_len] = n1 % 10 + '0';
	if (n < 0)
		res[0] = '-';
	return (res);
}
