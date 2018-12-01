/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:21:04 by hdanylev          #+#    #+#             */
/*   Updated: 2018/02/22 12:21:05 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_all	*ft_precision_num_minus(t_all *all)
{
	int i;

	i = 0;
	if (all->output[0] == '-')
	{
		all->prec++;
		write(1, "-", 1);
	}
	if (all->lat[3].flag == 1)
		all->lat[3].f(all);
	all->prec = all->prec < 0 ? 0 : all->prec;
	all->len += all->prec;
	i = all->prec;
	if (all->lat[0].flag == 1 && all->lat[1].flag != 1)
		all->lat[0].f(all);
	while (i > 0)
	{
		write(1, "0", 1);
		i--;
	}
	if (all->lat[6].flag == 1)
		all->lat[6].f(all);
	return (all);
}

t_all	*ft_prec_num_2(t_all *all)
{
	if (all->output[0] == '-')
		all->prec++;
	all->prec = all->prec < 0 ? 0 : all->prec;
	if (all->lat[6].flag == 1)
		all->lat[6].f(all);
	if (all->output[0] == '-')
		write(1, "-", 1);
	else if (all->lat[3].flag == 1)
		all->lat[3].f(all);
	all->len += all->prec;
	if (all->lat[0].flag == 1 && all->lat[1].flag != 1 &&
			all->lat[6].flag != 1)
		all->lat[0].f(all);
	return (all);
}

t_all	*ft_precision_num(t_all *all)
{
	if (all->spc == 'x' || all->spc == 'X' || all->spc == 'p')
		all->prec = all->lat[5].num - all->lennumonly;
	else
		all->prec = all->lat[5].num - all->outlen;
	if (all->lat[2].flag == 1)
		ft_precision_num_minus(all);
	else
	{
		ft_prec_num_2(all);
		while (all->prec > 0)
		{
			write(1, "0", 1);
			all->prec--;
		}
	}
	return (all);
}

t_all	*ft_precision_s(t_all *all)
{
	int i;

	i = 0;
	while (i < all->lat[5].num && all->output[i])
	{
		write(1, &all->output[i], 1);
		i++;
	}
	all->printed = 1;
	if (all->lat[6].flag == 1)
		all->lat[6].f(all);
	all->len += i;
	return (all);
}

t_all	*ft_precision(t_all *all)
{
	int i;

	i = 0;
	if (all->spc == 's')
	{
		if (all->lat[2].flag == 1)
			ft_precision_s(all);
		else
		{
			all->printed = 1;
			if (all->lat[6].flag == 1)
				all->lat[6].f(all);
			while (i < all->lat[5].num && all->output[i])
			{
				write(1, &all->output[i], 1);
				i++;
			}
			all->len += i;
		}
		return (all);
	}
	else
		return (ft_precision_num(all));
}
