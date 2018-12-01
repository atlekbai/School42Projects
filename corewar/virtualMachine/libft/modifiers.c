/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:23:42 by hdanylev          #+#    #+#             */
/*   Updated: 2018/01/27 18:16:33 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_all	*ft_z(t_all *all)
{
	size_t	z;

	z = 0;
	if (all->spc == 'i' || all->spc == 'd')
	{
		z = va_arg(all->conv, size_t);
		all->output = ft_itoa_base_l(z, 10);
	}
	else if (all->spc == 'o' || all->spc == 'u' ||
			all->spc == 'x' || all->spc == 'X')
	{
		z = va_arg(all->conv, size_t);
		if (all->spc == 'o')
			all->output = ft_itoa_base(z, 8);
		else if (all->spc == 'x' || all->spc == 'X')
			all->output = ft_itoa_base(z, 16);
		else
			all->output = ft_itoa_base(z, 10);
	}
	ft_count_output(all);
	ft_check_lat2(all);
	return (all);
}

t_all	*ft_j(t_all *all)
{
	intmax_t	ss;
	uintmax_t	us;

	ss = 0;
	us = 0;
	if (all->spc == 'i' || all->spc == 'd')
	{
		ss = va_arg(all->conv, intmax_t);
		all->output = ft_itoa_base_l(ss, 10);
	}
	else if (all->spc == 'o' || all->spc == 'u' ||
			all->spc == 'x' || all->spc == 'X')
	{
		us = va_arg(all->conv, uintmax_t);
		if (all->spc == 'o')
			all->output = ft_itoa_base(us, 8);
		else if (all->spc == 'x' || all->spc == 'X')
			all->output = ft_itoa_base(us, 16);
		else
			all->output = ft_itoa_base(us, 10);
	}
	ft_count_output(all);
	ft_check_lat2(all);
	return (all);
}

t_all	*ft_h(t_all *all)
{
	signed short	ss;
	unsigned short	us;

	ss = 0;
	us = 0;
	if (all->spc == 'i' || all->spc == 'd')
	{
		ss = (signed short)va_arg(all->conv, int);
		all->output = ft_itoa_base_l(ss, 10);
	}
	else if (all->spc == 'o' || all->spc == 'u' ||
			all->spc == 'x' || all->spc == 'X')
	{
		us = (unsigned short)va_arg(all->conv, int);
		if (all->spc == 'o')
			all->output = ft_itoa_base(us, 8);
		else if (all->spc == 'x' || all->spc == 'X')
			all->output = ft_itoa_base(us, 16);
		else
			all->output = ft_itoa_base(us, 10);
	}
	ft_count_output(all);
	ft_check_lat2(all);
	return (all);
}

t_all	*ft_hh(t_all *all)
{
	signed char		sc;
	unsigned char	uc;

	sc = 0;
	uc = 0;
	if (all->spc == 'i' || all->spc == 'd')
	{
		sc = (signed char)va_arg(all->conv, int);
		all->output = ft_itoa_base_l(sc, 10);
	}
	else if (all->spc == 'o' || all->spc == 'u' ||
			all->spc == 'x' || all->spc == 'X')
	{
		uc = (unsigned char)va_arg(all->conv, int);
		if (all->spc == 'o')
			all->output = ft_itoa_base(uc, 8);
		else if (all->spc == 'x' || all->spc == 'X')
			all->output = ft_itoa_base(uc, 16);
		else
			all->output = ft_itoa_base(uc, 10);
	}
	ft_count_output(all);
	ft_check_lat2(all);
	return (all);
}

t_all	*ft_l(t_all *all)
{
	if (all->spc == 'i' || all->spc == 'd' || all->spc == 'D')
	{
		all->l = va_arg(all->conv, long);
		all->output = ft_itoa_base_l(all->l, 10);
	}
	else if (all->spc == 'o' || all->spc == 'O' || all->spc == 'u' ||
			all->spc == 'U' || all->spc == 'x' || all->spc == 'X')
	{
		all->ul = va_arg(all->conv, unsigned long);
		if (all->spc == 'o' || all->spc == 'O')
			all->output = ft_itoa_base(all->ul, 8);
		else if (all->spc == 'x' || all->spc == 'X')
			all->output = ft_itoa_base(all->ul, 16);
		else
			all->output = ft_itoa_base(all->ul, 10);
	}
	else if (all->spc == 'c' || all->spc == 'C' ||
			all->spc == 's' || all->spc == 'S')
		return (ft_unicode(all));
	ft_count_output(all);
	ft_check_lat2(all);
	return (all);
}
