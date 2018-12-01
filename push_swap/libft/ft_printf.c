/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:52:28 by hdanylev          #+#    #+#             */
/*   Updated: 2018/02/13 16:38:20 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	free_all(t_all *all)
{
	free(all->capa);
	free(all->mod);
	free(all->lat);
	free(all);
}

t_all	*write_flags(t_all *all)
{
	const char	*spc;
	const char	*mod;
	const char	*lat;
	int			i;

	spc = "sSpdDioOuUxXcC";
	mod = "SDOUCHhljz";
	lat = "#0-+ .w";
	i = -1;
	while (spc[++i])
		all->capa[i].spc = spc[i];
	i = -1;
	while (mod[++i])
	{
		all->mod[i].mod = mod[i];
		all->mod[i].flag = 0;
	}
	i = -1;
	while (lat[++i])
	{
		all->lat[i].lat = lat[i];
		all->lat[i].flag = 0;
		all->lat[i].num = 0;
	}
	return (all);
}

t_all	*build_struct(t_all *all)
{
	all->capa = (t_capa*)malloc(sizeof(t_capa) * 14);
	all->mod = (t_mod*)malloc(sizeof(t_mod) * 10);
	all->lat = (t_lat*)malloc(sizeof(t_lat) * 7);
	functions_pointers_capa(all);
	functions_pointers_mod(all);
	functions_pointers_flag(all);
	write_flags(all);
	ft_null(all);
	return (all);
}

t_all	*ft_read_lol(t_all *all, char *fmt)
{
	int x;
	int flag;

	x = 0;
	flag = 0;
	while (fmt[x] && flag != 1)
	{
		if (fmt[x] == 'h' && fmt[x + 1] == 'h')
			ft_check_mod(all, 'H');
		ft_check_mod(all, fmt[x]);
		ft_check_lat(all, &fmt[x]);
		ft_check_capa(all, fmt[x]);
		flag = all->flag_stop;
		if (fmt[x] >= '0' && fmt[x] <= '9')
			while (fmt[x] >= '0' && fmt[x] <= '9')
				x++;
		else
			x++;
	}
	if (fmt[x] == '\0' && flag != 1)
		ft_persent(all);
	all->x = x;
	ft_zero_flag(all);
	return (all);
}

int		ft_printf(const char *fmt, ...)
{
	int		i;
	int		len;
	t_all	*all;

	all = (t_all*)malloc(sizeof(t_all));
	build_struct(all);
	i = -1;
	len = 0;
	va_start(all->conv, fmt);
	while (fmt[++i])
	{
		if (fmt[i] == '%' && fmt[i + 1] != '%')
		{
			ft_read_lol(all, (char *)&fmt[i + 1]);
			i += all->x;
		}
		else if (fmt[i] == '%' && fmt[i + 1] == '%' && i++ && len++)
			write(1, &fmt[i], 1);
		else if (len += 1)
			write(1, &fmt[i], 1);
	}
	va_end(all->conv);
	len += all->len;
	free_all(all);
	return (len);
}
