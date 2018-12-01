/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:27:23 by atlekbai          #+#    #+#             */
/*   Updated: 2018/04/13 21:27:23 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_l(uintmax_t n, uintmax_t b, char *res, int *i)
{
	char const signs[] = "0123456789abcdef";

	if (n >= b)
		fill_l(n / b, b, res, i);
	res[(*i)++] = signs[ABS(n % b)];
}

static void	fill_u(uintmax_t n, uintmax_t b, char *res, int *i)
{
	char const signs[] = "0123456789ABCDEF";

	if (n >= b)
		fill_u(n / b, b, res, i);
	res[(*i)++] = signs[ABS(n % b)];
}

char		*long_itoa_base(uintmax_t n, uintmax_t base, int c)
{
	char	*res;
	int		i;

	if (base < 2 || base > 16 || !(res = (char *)malloc(sizeof(char) * 50)))
		return (NULL);
	i = 0;
	if (c == 0)
		fill_l(n, base, res, &i);
	else
		fill_u(n, base, res, &i);
	res[i] = '\0';
	return (res);
}

static void	giant_fill(int64_t n, int64_t b, char *res, int *i)
{
	char const signs[] = "0123456789abcdef";

	if (n <= -b || n >= b)
		giant_fill(n / b, b, res, i);
	res[(*i)++] = signs[ABS(n % b)];
}

char		*giant_itoa_base(int64_t n, int64_t base)
{
	char	*res;
	int		i;

	if (base < 2 || base > 16 || !(res = (char *)malloc(sizeof(char) * 50)))
		return (NULL);
	i = 0;
	giant_fill(n, base, res, &i);
	res[i] = '\0';
	return (res);
}
