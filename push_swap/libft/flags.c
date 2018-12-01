/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:59:20 by hdanylev          #+#    #+#             */
/*   Updated: 2018/02/26 13:59:43 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_all	*ft_space(t_all *all)
{
	if (all->spc == 'd' || all->spc == 'i' || all->spc == 'D')
	{
		if (all->output[0] != '-' && all->lat[3].flag != 1)
		{
			write(1, " ", 1);
			all->len += 1;
			all->width--;
		}
	}
	return (all);
}

t_all	*ft_plus(t_all *all)
{
	if (all->spc == 'd' || all->spc == 'i' || all->spc == 'D')
	{
		if (all->output[0] != '-')
		{
			write(1, "+", 1);
			all->len += 1;
			if ((all->lat[1].flag != 1 || all->lat[2].flag == 1) &&
					all->lat[5].flag != 1)
				ft_output(all);
		}
	}
	return (all);
}

t_all	*ft_hash(t_all *all)
{
	if (all->output[0] == '0' && all->spc != 'p')
		return (all);
	if ((all->spc == 'x' || all->spc == 'X' || all->spc == 'p') &&
			all->printed != 1)
	{
		if (all->spc == 'X')
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
		if ((all->lat[1].flag != 1 || all->lat[2].flag == 1) &&
				all->lat[5].flag != 1)
			ft_output(all);
		all->len += 2;
		all->flag_was = 1;
	}
	else if ((all->spc == 'o' || all->spc == 'O') && all->printed != 1)
	{
		write(1, "0", 1);
		if (all->lat[1].flag != 1 && all->lat[2].flag == 1)
			ft_output(all);
		all->len += 1;
		all->flag_was = 1;
	}
	return (all);
}

t_all	*ft_minus(t_all *all)
{
	if (all->lat[0].flag == 1)
		all->lat[0].f(all);
	else if (all->lat[4].flag == 1)
		all->lat[4].f(all);
	else if (all->printed != 1)
		ft_output(all);
	all->printed = 1;
	return (all);
}

char	ft_zero(t_all *all)
{
	if (all->lat[1].flag == 1 && all->lat[2].flag != 1 && all->lat[5].flag != 1)
	{
		if (all->output[0] == '-')
			write(1, "-", 1);
		else if (all->lat[3].flag == 1)
			all->lat[3].f(all);
		return ('0');
	}
	return (' ');
}
