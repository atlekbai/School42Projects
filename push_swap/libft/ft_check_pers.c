/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_%.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:08:54 by hdanylev          #+#    #+#             */
/*   Updated: 2018/02/18 16:09:23 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_all	*ft_persent(t_all *all)
{
	all->spc = '%';
	all->output = (char*)malloc(sizeof(char) * 2);
	all->output[0] = '%';
	all->output[1] = '\0';
	ft_count_output(all);
	ft_check_lat2(all);
	if (all->printed != 1)
		ft_output(all);
	return (all);
}

t_all	*ft_check_lat(t_all *all, char *fmt)
{
	int b;

	b = -1;
	while (++b < 5)
	{
		if (all->lat[b].lat == fmt[0])
		{
			all->lat[b].flag = 1;
		}
		else if (fmt[0] >= '0' && fmt[0] <= '9' && all->lat[5].flag == 0)
		{
			all->lat[6].num = ft_atoi(&fmt[0]);
			all->lat[6].flag = 1;
		}
		else if (fmt[0] == '.')
		{
			all->lat[5].num = ft_atoi(&fmt[1]);
			all->lat[5].flag = 1;
		}
	}
	return (all);
}

t_all	*ft_check_mod(t_all *all, char x)
{
	int b;

	b = -1;
	while (++b < 10)
		if (all->mod[b].mod == x)
			all->mod[b].flag = 1;
	return (all);
}

t_all	*ft_check_capa(t_all *all, char x)
{
	int b;

	b = -1;
	while (++b < 14)
		if (all->capa[b].spc == x)
		{
			all->capa[b].flag = 1;
			all->spc = all->capa[b].spc;
			all->len = all->capa[b].f(all);
			all->flag_stop = 1;
		}
	return (all);
}
