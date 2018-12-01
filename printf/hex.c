/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:55:26 by atlekbai          #+#    #+#             */
/*   Updated: 2018/04/13 21:11:26 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_hex_minus(t_spec spec, char *hash, char *str, char **all)
{
	*all = ft_strjoin_free(*all, hash);
	while (spec.precision-- > 0)
		*all = ft_stradd(*all, 48);
	*all = ft_strjoin_free(*all, str);
	while (spec.pad-- > 0)
		*all = ft_stradd(*all, 32);
}

static void			ft_hex_usual(t_spec spec, char *hash, char *str, char **all)
{
	char	fill;

	fill = 32;
	if (ft_strchr(spec.flags, '0') && spec.precision == -1)
	{
		fill = 48;
		*all = ft_strjoin_free(*all, hash);
		hash = "";
	}
	while (spec.pad-- > 0)
		*all = ft_stradd(*all, fill);
	*all = ft_strjoin_free(*all, hash);
	while (spec.precision-- > 0)
		*all = ft_stradd(*all, 48);
	if (str)
		*all = ft_strjoin_free(*all, str);
}

static uintmax_t	get_by_type(t_spec spec, va_list ap, char **str, int c)
{
	uintmax_t d;

	d = 0;
	if (spec.mod == NULL)
		d = (unsigned int)va_arg(ap, long);
	else if (ft_strcmp(spec.mod, "hh") == 0)
		d = (unsigned char)va_arg(ap, int);
	else if (ft_strcmp(spec.mod, "h") == 0)
		d = (unsigned short)va_arg(ap, int);
	else if (ft_strcmp(spec.mod, "ll") == 0 || ft_strcmp(spec.mod, "l") == 0
			|| spec.letter == 'O')
		d = va_arg(ap, uintmax_t);
	else if (ft_strcmp(spec.mod, "j") == 0)
		d = va_arg(ap, uintmax_t);
	else if (ft_strcmp(spec.mod, "z") == 0)
		d = va_arg(ap, size_t);
	*str = long_itoa_base(d, 16, c);
	return (d);
}

static int			res(t_spec spec, char *hash, int len, uintmax_t d)
{
	int res;

	res = (spec.pad < 0) ? len : spec.pad + len;
	if (spec.precision != -1)
		res = (spec.pad < 0) ? spec.precision + len :
			spec.pad + spec.precision + len;
	res += ft_strlen(hash);
	d = 2;
	if (d != 0)
		ft_strdel(&hash);
	return (res);
}

int					ft_hex(t_spec spec, va_list ap, char **all)
{
	uintmax_t	d;
	char		*hash;
	int			c;
	char		*str;
	int			len;

	c = (spec.letter == 'X') ? 1 : 0;
	d = get_by_type(spec, ap, &str, c);
	len = ft_strlen(str);
	spec.pad = spec.field_w - len;
	hex_helper(&spec, &str, &len, d);
	hash = ft_strnew(2);
	hash = (spec.letter == 'p' || (ft_strchr(spec.flags, '#') && d != 0))
			? ft_strcpy(hash, "0") : hash;
	if (ft_strlen(hash) == 1)
		hash = (!c) ? ft_strcat(hash, "x") : ft_strcat(hash, "X");
	spec.pad -= ft_strlen(hash);
	ft_strchr(spec.flags, '-') ? ft_hex_minus(spec, hash, str, all)
			: ft_hex_usual(spec, hash, str, all);
	ft_strdel(&str);
	return (res(spec, hash, len, d));
}
