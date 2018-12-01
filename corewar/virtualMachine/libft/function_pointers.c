/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_pointers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:43:25 by hdanylev          #+#    #+#             */
/*   Updated: 2018/01/27 17:45:26 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_all	*ft_null(t_all *all)
{
	all->len = 0;
	all->l = 0;
	all->ul = 0;
	all->ret = 0;
	all->printed = 0;
	all->flag_stop = 0;
	all->flag_was = 0;
	all->lennumonly = 0;
	all->outlen = 0;
	all->prec = 0;
	all->x = 0;
	all->width = 0;
	all->output = NULL;
	all->up = NULL;
	return (all);
}

t_all	*ft_zero_flag(t_all *all)
{
	int i;

	i = -1;
	while (++i < 14)
		all->capa[i].flag = 0;
	i = -1;
	while (++i < 9)
		all->mod[i].flag = 0;
	i = -1;
	while (++i < 7)
		all->lat[i].flag = 0;
	all->ret = 0;
	all->printed = 0;
	all->flag_stop = 0;
	all->flag_was = 0;
	return (all);
}

t_all	*functions_pointers_capa(t_all *all)
{
	all->capa[0].f = &ft_s;
	all->capa[1].f = &ft_s;
	all->capa[2].f = &ft_p;
	all->capa[3].f = &ft_id;
	all->capa[4].f = &ft_id;
	all->capa[5].f = &ft_id;
	all->capa[6].f = &ft_o;
	all->capa[7].f = &ft_o;
	all->capa[8].f = &ft_u;
	all->capa[9].f = &ft_u;
	all->capa[10].f = &ft_x;
	all->capa[11].f = &ft_x;
	all->capa[12].f = &ft_c;
	all->capa[13].f = &ft_c;
	return (all);
}

t_all	*functions_pointers_flag(t_all *all)
{
	all->lat[0].f = &ft_hash;
	all->lat[2].f = &ft_minus;
	all->lat[3].f = &ft_plus;
	all->lat[4].f = &ft_space;
	all->lat[5].f = &ft_precision;
	all->lat[6].f = &ft_field_width;
	return (all);
}

t_all	*functions_pointers_mod(t_all *all)
{
	all->mod[0].f = &ft_l;
	all->mod[1].f = &ft_l;
	all->mod[2].f = &ft_l;
	all->mod[3].f = &ft_l;
	all->mod[4].f = &ft_l;
	all->mod[5].f = &ft_hh;
	all->mod[6].f = &ft_h;
	all->mod[7].f = &ft_l;
	all->mod[8].f = &ft_j;
	all->mod[9].f = &ft_z;
	return (all);
}
