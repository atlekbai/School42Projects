/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:33:38 by hdanylev          #+#    #+#             */
/*   Updated: 2018/01/27 18:16:49 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_c(t_all *all)
{
	char	c;

	ft_check_mod2(all);
	if (all->ret == -22)
	{
		c = (unsigned char)va_arg(all->conv, int);
		all->output = (char*)malloc(sizeof(char) * 2);
		all->output[0] = c;
		all->output[1] = '\0';
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

int		ft_o(t_all *all)
{
	unsigned int	o;

	ft_check_mod2(all);
	if (all->ret == -22)
	{
		o = va_arg(all->conv, unsigned int);
		all->output = ft_itoa_base(o, 8);
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

int		ft_x(t_all *all)
{
	unsigned int	x;

	ft_check_mod2(all);
	if (all->ret == -22)
	{
		x = va_arg(all->conv, unsigned int);
		all->output = ft_itoa_base(x, 16);
		ft_count_output(all);
		if (all->spc == 'X')
			ft_toupper(all->output);
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

int		ft_id(t_all *all)
{
	int	id;

	ft_check_mod2(all);
	if (all->ret == -22)
	{
		id = va_arg(all->conv, int);
		all->output = ft_itoa(id);
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

int		ft_u(t_all *all)
{
	unsigned int	u;

	ft_check_mod2(all);
	if (all->ret == -22)
	{
		u = va_arg(all->conv, unsigned int);
		all->output = ft_itoa(u);
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
