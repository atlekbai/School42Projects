/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:52:59 by atlekbai          #+#    #+#             */
/*   Updated: 2018/04/10 16:03:08 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define ABS(x) ((x < 0) ? -(x) : (x))

static void	fill(int64_t n, int64_t b, char *res, int *i)
{
	char const signs[] = "0123456789abcdef";

	if (n <= -b || n >= b)
		fill(n / b, b, res, i);
	res[(*i)++] = signs[ABS(n % b)];
}

char		*ft_itoa_base(int64_t n, int64_t base)
{
	char	*res;
	int		i;

	if (base < 2 || base > 16 || !(res = (char *)malloc(sizeof(char) * 50)))
		return (NULL);
	i = 0;
	if (base == 10 && n < 0)
		res[i++] = '-';
	fill(n, base, res, &i);
	res[i] = '\0';
	return (res);
}
