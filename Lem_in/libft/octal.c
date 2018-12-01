/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:11:57 by atlekbai          #+#    #+#             */
/*   Updated: 2018/04/13 21:11:57 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			min(t_spec spec, char *str, char **all)
{
	char *temp;

	while (spec.precision-- > 0)
		*all = ft_stradd(*all, 48);
	if (!str)
	{
		temp = giant_itoa_base(0, 10);
		*all = ft_strjoin_free(*all, temp);
	}
	else
	{
		temp = *all;
		*all = ft_strjoin_free(temp, str);
	}
	while (spec.pad-- > 0)
		*all = ft_stradd(*all, 32);
}

static void			us(t_spec spec, char *str, char **all)
{
	char	fill;
	char	*temp;

	fill = 32;
	if (ft_strchr(spec.flags, '0') && spec.precision == -1)
		fill = 48;
	while (spec.pad-- > 0)
		*all = ft_stradd(*all, fill);
	while (spec.precision-- > 0)
		*all = ft_stradd(*all, 48);
	if (!str && ft_strchr(spec.flags, '#'))
	{
		temp = giant_itoa_base(0, 10);
		*all = ft_strjoin_free(*all, temp);
	}
	else if (str)
	{
		temp = *all;
		*all = ft_strjoin_free(temp, str);
	}
}

static uintmax_t	gbt(t_spec spec, va_list ap, char **str, int base)
{
	uintmax_t d;

	d = 0;
	if (ft_strcmp(spec.mod, "ll") == 0 || ft_strcmp(spec.mod, "l") == 0
			|| spec.letter == 'O' || spec.letter == 'U')
		d = va_arg(ap, uintmax_t);
	else if (spec.mod == NULL)
		d = (unsigned int)va_arg(ap, long);
	else if (ft_strcmp(spec.mod, "hh") == 0)
		d = (unsigned char)va_arg(ap, int);
	else if (ft_strcmp(spec.mod, "h") == 0)
		d = (unsigned short)va_arg(ap, int);
	else if (ft_strcmp(spec.mod, "j") == 0)
		d = va_arg(ap, uintmax_t);
	else if (ft_strcmp(spec.mod, "z") == 0)
		d = va_arg(ap, size_t);
	*str = long_itoa_base(d, base, 0);
	return (d);
}

static int			res(t_spec spec, int len, char **str)
{
	int res;

	res = (spec.pad < 0) ? len : spec.pad + len;
	if (spec.precision != -1)
		res = (spec.pad < 0) ? spec.precision + len :
			spec.pad + spec.precision + len;
	res += (ft_strchr(spec.flags, '#') && spec.precision <= 0) ? 1 : 0;
	free(*str);
	return (res);
}

int					ft_octal(t_spec spec, va_list ap, char **all)
{
	uintmax_t	d;
	int			base;
	char		*str;
	int			len;
	char		*temp;

	base = (spec.letter == 'o' || spec.letter == 'O') ? 8 : 10;
	d = gbt(spec, ap, &str, base);
	len = ft_strlen(str);
	spec.pad = spec.field_w - len;
	if (d == 0 && (ft_strchr(spec.flags, '#') || spec.prec == 1))
	{
		free(str);
		str = ft_strnew(0);
		len = 0;
	}
	if (spec.prec == 1)
	{
		spec.precision = spec.precision - len;
		spec.precision = (spec.precision < 0) ? 0 : spec.precision;
		spec.pad = spec.field_w - spec.precision - len;
	}
	octal_helper(&spec, &str, &temp);
	(ft_strchr(spec.flags, '-')) ? min(spec, str, all) : us(spec, str, all);
	return (res(spec, len, &str));
}
