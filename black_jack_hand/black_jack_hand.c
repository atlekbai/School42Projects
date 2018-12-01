/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black_jack_hand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 17:03:02 by atlekbai          #+#    #+#             */
/*   Updated: 2018/10/12 17:21:50 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	count_a(char *str)
{
	int res;

	res = 0;
	while (*str)
	{
		if (*str == 'A')
			res++;
		str++;
	}
	return (res);
}

int	black_jack_hand(char *str)
{
	int	a;
	int res;

	a = count_a(str);
	res = 0;
	while (*str)
	{
		if (*str >= '2' && *str <= '9')
			res += *str - '0';
		else if (*str == 'T' || *str == 'J' || *str == 'D' || *str == 'K')
			res += 10;
		str++;
	}
	if (res >= 21)
		res += a;
	else
	{
		while (a-- > 0)
		{
			if (res + 11 * (a + 1) <= 21)
			{
				res += 11 * (a + 1);
				break;
			}
			res++;
		}
	}
	return (res);
}

int main(int ac, char **av)
{
	printf("%d\n", black_jack_hand(av[1]));
	return (0);
}
