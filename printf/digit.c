/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:42:23 by atlekbai          #+#    #+#             */
/*   Updated: 2018/04/13 19:47:09 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_minus(t_spec spec, char plus, char *str, char **all)
{
	if (plus != 0)
		*all = ft_stradd(*all, plus);
	while (spec.precision-- > 0)
		*all = ft_stradd(*all, 48);
	if (str)
		*all = ft_strjoin_free(*all, str);
	while (spec.pad-- > 0)
		*all = ft_stradd(*all, 32);
}

static void		ft_usual(t_spec spec, char plus, char *str, char **all)
{
	char fill;

	fill = 32;
	if (ft_strchr(spec.flags, '0') && spec.precision <= -1)
	{
		fill = 48;
		if (plus != 0)
			*all = ft_stradd(*all, plus);
		plus = 0;
	}
	if (spec.precision != -1)
		fill = 32;
	while (spec.pad-- > 0)
		*all = ft_stradd(*all, fill);
	if (plus != 0)
		*all = ft_stradd(*all, plus);
	while (spec.precision-- > 0)
		*all = ft_stradd(*all, 48);
	if (str)
		*all = ft_strjoin_free(*all, str);
}

static int64_t	get_by_type(t_spec spec, va_list ap, char **str)
{
	int64_t d;

	d = 0;
	if (ft_strcmp(spec.mod, "ll") == 0 ||
		ft_strcmp(spec.mod, "l") == 0 || spec.letter == 'D')
		d = va_arg(ap, long);
	else if (spec.mod == NULL && spec.letter != 'D')
		d = va_arg(ap, int);
	else if (ft_strcmp(spec.mod, "hh") == 0)
		d = (signed char)va_arg(ap, int);
	else if (ft_strcmp(spec.mod, "h") == 0)
		d = (short)va_arg(ap, int);
	else if (ft_strcmp(spec.mod, "j") == 0)
		d = va_arg(ap, intmax_t);
	else if (ft_strcmp(spec.mod, "z") == 0)
		d = va_arg(ap, size_t);
	*str = giant_itoa_base(d, 10);
	return (d);
}

static int		res(t_spec spec, char **str, char plus)
{
	int res;
	int len;

	len = 0;
	if (*str)
		len = ft_strlen(*str);
	res = (spec.pad < 0) ? len : spec.pad + len;
	if (spec.precision != -1)
		res = (spec.pad < 0) ? spec.precision + len :
			spec.pad + spec.precision + len;
	res += (ft_strchr(spec.flags, '+') && plus != '-') ? 1 : 0;
	res += (plus == '-') ? 1 : 0;
	if (*str)
		ft_strdel(str);
	return (res);
}

int				ft_digit(t_spec spec, va_list ap, char **all)
{
	int64_t		d;
	char		plus;
	char		*str;
	int			len;

	d = get_by_type(spec, ap, &str);
	plus = (d < 0) ? '-' : 0;
	len = ft_strlen(str);
	spec.pad = spec.field_w - len;
	ft_dgt_helper(&spec, &len, d, &str);
	spec.pad -= (d < 0) ? 1 : 0;
	if (ft_strchr(spec.flags, '+'))
	{
		plus = (d < 0) ? '-' : '+';
		spec.pad -= (d >= 0) ? 1 : 0;
	}
	ft_strchr(spec.flags, '-') ? ft_minus(spec, plus, str, all)
		: ft_usual(spec, plus, str, all);
	return (res(spec, &str, plus));
}
