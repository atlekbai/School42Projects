/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 17:09:52 by hdanylev          #+#    #+#             */
/*   Updated: 2018/05/31 12:55:04 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_all	*ft_put_num_minus(t_all *all, int width)
{
	char	ch;

	if (all->lat[0].flag == 1)
		all->lat[0].f(all);
	if (all->lat[3].flag == 1 && all->lat[5].flag != 1)
		all->lat[3].f(all);
	all->lat[2].f(all);
	ch = ft_zero(all);
	all->len += width;
	while (width > 0)
	{
		write(1, &ch, 1);
		width--;
	}
	return (all);
}

t_all	*ft_put_width_num(t_all *all)
{
	char	ch;

	all->width = all->lat[6].num - all->outlen - all->prec;
	all->width = all->width <= 0 ? 0 : all->width;
	if (all->lat[4].flag == 1)
		all->lat[4].f(all);
	if (all->lat[2].flag == 1)
		ft_put_num_minus(all, all->width);
	else
	{
		if (all->lat[1].flag == 1 && all->lat[0].flag == 1 &&
				all->width > 0 && all->lat[5].flag != 1)
			all->lat[0].f(all);
		ch = ft_zero(all);
		all->len += all->width;
		while (all->width > 0)
		{
			write(1, &ch, 1);
			all->width--;
		}
		if (all->lat[0].flag == 1 && all->flag_was != 1)
			all->lat[0].f(all);
	}
	return (all);
}

t_all	*ft_put_width_str(t_all *all)
{
	char	ch;

	if (all->lat[5].num <= all->outlen && all->lat[5].num)
		all->width = all->lat[6].num - all->lat[5].num;
	else
		all->width = all->lat[6].num - all->outlen;
	if (all->lat[2].flag == 1)
		all->lat[2].f(all);
	if (all->width < 0)
		all->width = 0;
	all->len += all->width;
	ch = ' ';
	while (all->width > 0)
	{
		write(1, &ch, 1);
		all->width--;
	}
	return (all);
}

t_all	*ft_field_width(t_all *all)
{
	if (all->spc == 's')
		return (ft_put_width_str(all));
	else
		return (ft_put_width_num(all));
}
