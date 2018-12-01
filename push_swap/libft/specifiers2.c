/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:19:08 by hdanylev          #+#    #+#             */
/*   Updated: 2018/03/01 18:19:26 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_p(t_all *all)
{
	intptr_t	*p;

	p = va_arg(all->conv, void*);
	all->output = ft_itoa_base((unsigned long)p, 16);
	all->lat[0].flag = 1;
	ft_count_output(all);
	ft_check_lat2(all);
	if (all->ret == -42)
	{
		write(1, "0x", 2);
		ft_output(all);
		all->printed = 1;
		return (all->len + 2);
	}
	if (all->printed != 1)
		ft_output(all);
	return (all->len);
}

int		ft_s(t_all *all)
{
	char *str;

	ft_check_mod2(all);
	if (all->ret == -22)
	{
		str = va_arg(all->conv, char*);
		all->output = ft_strdup(str);
		if (all->output == NULL)
			all->output = ft_strdup("(null)");
		ft_count_output(all);
		ft_check_lat2(all);
		if (all->ret == -42)
		{
			ft_output(all);
			return (all->len);
		}
	}
	if (all->printed != 1)
		ft_output(all);
	return (all->len);
}

t_all	*ft_count_output(t_all *all)
{
	all->outlen = ft_strlen(all->output);
	all->lennumonly = all->outlen;
	if (all->lat[5].flag == 1 && all->lat[5].num == 0 && all->output[0] == '0')
	{
		if (all->spc != 'o' || all->lat[0].flag != 1)
		{
			all->printed = 1;
			all->outlen -= 1;
		}
	}
	if (all->output[0] == '\0' && all->spc == 'c')
		all->outlen = 1;
	if (all->lat[0].flag == 1)
	{
		if (all->spc == 'x' || all->spc == 'X' || all->spc == 'p')
			all->outlen += 2;
		else if (all->spc == 'o' || all->spc == 'O')
			all->outlen += 1;
	}
	if (all->lat[3].flag == 1)
		if ((all->spc == 'D' || all->spc == 'd' || all->spc == 'i')
			&& all->output[0] != '-')
			all->lat[6].num -= 1;
	return (all);
}
