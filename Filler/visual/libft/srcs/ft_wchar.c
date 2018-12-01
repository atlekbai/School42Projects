/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:08:55 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/02/23 17:14:32 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_take_wlen(const uint32_t symbol)
{
	int	size;

	size = 0;
	if (symbol <= BIT7)
		size += 1;
	else if (symbol <= BIT11)
		size += 2;
	else if (symbol <= BIT16)
		size += 3;
	else if (symbol <= BIT21)
		size += 4;
	return (size);
}

char	*ft_parse_wchar(const uint32_t symbol, int p)
{
	char	*rt;

	rt = ft_strnew(4);
	if (symbol <= BIT7 && p >= 1)
		rt[0] = symbol;
	else if (symbol <= BIT11 && p >= 2)
	{
		rt[0] = ((symbol & 1984) >> 6) | 192;
		rt[1] = (symbol & 63) | 128;
	}
	else if (symbol <= BIT16 && p >= 3)
	{
		rt[0] = ((symbol & 61440) >> 12) | 224;
		rt[1] = ((symbol & 4032) >> 6) | 128;
		rt[2] = (symbol & 63) | 128;
	}
	else if (symbol <= BIT21 && p >= 4)
	{
		rt[0] = ((symbol & 1835008) >> 18) | 240;
		rt[1] = ((symbol & 258048) >> 12) | 128;
		rt[2] = ((symbol & 4032) >> 6) | 128;
		rt[3] = (symbol & 63) | 128;
	}
	return (rt);
}

void	ft_zeroing_wstr(char **data, t_desc *list, int fd)
{
	if (list->flag_zero == 1 && list->width > ft_wstrlen(data) &&
		list->flag_min == 0)
	{
		ft_put_zero_fd(list->width - ft_wstrlen(data), fd);
		ft_putwstr_fd(data, fd);
	}
	else if (list->flag_min == 1 && list->width > ft_wstrlen(data))
	{
		ft_putwstr_fd(data, fd);
		ft_place_shift_fd(list->width - ft_wstrlen(data), fd);
	}
	else if (list->flag_min == 0 && list->width != 0 &&
		list->width > ft_wstrlen(data))
	{
		ft_place_shift_fd(list->width - ft_wstrlen(data), fd);
		ft_putwstr_fd(data, fd);
	}
	else
		ft_putwstr_fd(data, fd);
}

void	ft_wchar_null(char *data, t_desc *list, int fd)
{
	if (list->prec != -2 && list->prec != -1)
		data = ft_makestr_prec(data, list);
	data = ft_zeroing_string(data, list);
	ft_flag_set_fd(data, list, fd);
}

void	ft_go_wstr(t_desc *list, wchar_t *data, int fd)
{
	char	**str;
	int		i;
	int		p;

	i = 0;
	while (data[i])
		i++;
	str = (char**)malloc(sizeof(char*) * (i + 1));
	str[i] = NULL;
	p = list->prec;
	i = 0;
	while (data[i])
	{
		if (list->prec < 0)
			p = 4;
		str[i] = ft_parse_wchar(data[i], p);
		p -= ft_take_wlen(data[i]);
		i++;
	}
	ft_zeroing_wstr(str, list, fd);
	ft_strdel_array(str);
}
