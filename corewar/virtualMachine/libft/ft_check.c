/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:06:13 by hdanylev          #+#    #+#             */
/*   Updated: 2018/02/15 13:06:33 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_all	*ft_check_lat2(t_all *all)
{
	all->ret = 0;
	if (all->lat[5].flag == 1 && all->output[0])
		all->lat[5].f(all);
	else if (all->lat[6].flag == 1)
		all->lat[6].f(all);
	else if (all->lat[0].flag == 1)
		all->lat[0].f(all);
	else if (all->lat[3].flag == 1)
		all->lat[3].f(all);
	else if (all->lat[4].flag == 1)
		all->lat[4].f(all);
	else
		all->ret = -42;
	return (all);
}

t_all	*ft_check_mod2(t_all *all)
{
	int i;

	i = 0;
	while (i < 10)
	{
		if (all->mod[i].flag == 1 && all->ret == 0)
		{
			all->mod[i].f(all);
			return (all);
		}
		i++;
	}
	all->ret = -22;
	return (all);
}
