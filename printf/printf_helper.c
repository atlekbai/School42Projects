/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 23:38:04 by atlekbai          #+#    #+#             */
/*   Updated: 2018/04/17 23:38:05 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dgt_helper(t_spec *spec, int *len, int64_t d, char **str)
{
	if ((*spec).precision != -1)
	{
		(*spec).precision = (*spec).precision - *len;
		if ((*spec).precision <= 0 && d == 0)
		{
			ft_strdel(str);
			*len = 0;
		}
		(*spec).precision = ((*spec).precision < 0) ? 0 : (*spec).precision;
		(*spec).pad = (ft_strchr((*spec).flags, ' ') && (*spec).precision >
			(*spec).pad) ? 1 : (*spec).field_w - (*spec).precision - *len;
	}
	if (ft_strchr((*spec).flags, ' ') &&
		(ft_strchr((*spec).flags, '0') || (*spec).pad <= 0))
	{
		(*spec).precision = ((*spec).pad <= 0) ? 0 : (*spec).pad - *len;
		(*spec).pad = 1;
	}
}

void	octal_helper(t_spec *spec, char **str, char **temp)
{
	if (ft_strchr((*spec).flags, '#') && (*spec).precision <= 0)
	{
		*temp = ft_strjoin("0", *str);
		free(*str);
		*str = *temp;
		(*spec).pad--;
	}
}

void	hex_helper(t_spec *spec, char **str, int *len, uintmax_t d)
{
	if ((*spec).precision != -1)
	{
		(*spec).precision = (*spec).precision - *len;
		(*spec).precision = ((*spec).precision < 0) ? 0 : (*spec).precision;
		if ((*spec).precision == 0 && d == 0)
		{
			ft_strdel(str);
			*len = 0;
		}
		(*spec).pad = (*spec).field_w - (*spec).precision - *len;
	}
}
