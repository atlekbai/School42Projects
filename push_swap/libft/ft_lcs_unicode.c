/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcs_unicode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 11:37:05 by hdanylev          #+#    #+#             */
/*   Updated: 2018/02/12 11:37:08 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	four_b(unsigned int u)
{
	unsigned int a;
	unsigned int b;
	unsigned int c;
	unsigned int d;
	unsigned int clone;

	a = 0xF0;
	b = 0x80;
	c = 0x80;
	d = 0x80;
	clone = u & 0x7000;
	a = a | (clone >> 18);
	clone = u & 0x03F000;
	b = b | (clone >> 12);
	clone = u & 0x0FC0;
	c = c | (clone >> 6);
	d = d | (u & 0x003F);
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	write(1, &d, 1);
}

void	three_b(unsigned int u)
{
	unsigned int a;
	unsigned int b;
	unsigned int c;
	unsigned int clone;

	a = 0xE0;
	b = 0x80;
	c = 0x80;
	clone = u & 0xF000;
	a = a | (clone >> 12);
	clone = u & 0x0FC0;
	b = b | (clone >> 6);
	c = c | (u & 0x003F);
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}

void	two_b(unsigned int u)
{
	unsigned int a;
	unsigned int b;
	unsigned int clone;

	clone = u;
	a = 0xC0;
	b = 0x80;
	clone = clone & 0x07C0;
	a = a | (clone >> 6);
	b = b | (u & 0x003F);
	write(1, &a, 1);
	write(1, &b, 1);
}

t_all	*ft_str_unicode(t_all *all, unsigned int u)
{
	all->len += 1;
	if (u <= 0x007F || (MB_CUR_MAX == 1 && u <= 255))
		write(1, &u, 1);
	else if (u <= 0x07FF)
	{
		all->len += 1;
		two_b(u);
	}
	else if (u <= 0xFFFF)
	{
		all->len += 2;
		three_b(u);
	}
	else
	{
		four_b(u);
		all->len += 3;
	}
	all->printed = 1;
	return (all);
}

t_all	*ft_unicode(t_all *all)
{
	unsigned int	u;
	int				i;

	i = 0;
	if (all->spc == 's' || all->spc == 'S')
	{
		all->up = va_arg(all->conv, unsigned int*);
		if (all->up)
		{
			while (all->up[i])
			{
				ft_str_unicode(all, all->up[i]);
				i++;
			}
		}
		else
			return (ft_output(all));
	}
	else
	{
		u = va_arg(all->conv, unsigned int);
		ft_str_unicode(all, u);
	}
	return (all);
}
