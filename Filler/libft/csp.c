/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 23:22:55 by atlekbai          #+#    #+#             */
/*   Updated: 2018/04/12 23:23:03 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_char(t_spec spec, va_list ap)
{
	char	fill;
	int		res;
	wchar_t	c;
	int		len;

	c = (spec.letter == 'C' || ft_strchr(spec.mod, 'l'))
		? va_arg(ap, wchar_t) : (char)va_arg(ap, unsigned int);
	spec.pad = spec.field_w - 1;
	len = (spec.letter == 'c' && !ft_strchr(spec.mod, 'l')) ? 1 : get_bytes(c);
	res = (spec.pad < 0) ? len : spec.pad + len;
	fill = (ft_strchr(spec.flags, '0')) ? 48 : 32;
	if (ft_strchr(spec.flags, '-'))
	{
		fill = 32;
		(spec.letter == 'c' && !ft_strchr(spec.mod, 'l')) ?
			write(1, &c, 1) : ft_putchar(c);
		while (spec.pad-- > 0)
			ft_putchar(fill);
		return (res);
	}
	while (spec.pad-- > 0)
		ft_putchar(fill);
	(spec.letter == 'c' && !ft_strchr(spec.mod, 'l'))
		? write(1, &c, 1) : ft_putchar(c);
	return (res);
}

int	small_s(t_spec spec, va_list ap, char **all)
{
	int		res;
	char	fill;
	char	*str;

	str = va_arg(ap, char *);
	str = (!str) ? "(null)" : str;
	str = (spec.prec == 1) ? ft_strsub(str, 0, spec.precision) : str;
	spec.pad = spec.field_w - ft_strlen(str);
	res = (spec.pad < 0) ? ft_strlen(str) : spec.pad + ft_strlen(str);
	fill = (ft_strchr(spec.flags, '0')) ? 48 : 32;
	if (ft_strchr(spec.flags, '-'))
	{
		fill = 32;
		*all = ft_strjoin_free(*all, str);
		while (spec.pad-- > 0)
			*all = ft_stradd(*all, fill);
		return (res);
	}
	while (spec.pad-- > 0)
		*all = ft_stradd(*all, fill);
	*all = ft_strjoin_free(*all, str);
	return (res);
}

int	big_s(t_spec spec, va_list ap)
{
	int		res;
	char	fill;
	wchar_t	*str;

	str = va_arg(ap, wchar_t *);
	str = (!str) ? L"(null)" : str;
	if (big_s_check(str) == 0)
		return (-1);
	if (spec.prec == 1)
		str = wc_strsub(str, 0, spec.precision);
	spec.pad = spec.field_w - wc_strlen(str);
	res = (spec.pad < 0) ? wc_strlen(str) : spec.pad + wc_strlen(str);
	fill = (ft_strchr(spec.flags, '0')) ? 48 : 32;
	if (ft_strchr(spec.flags, '-'))
	{
		fill = 32;
		wc_putstr(str);
		while (spec.pad-- > 0)
			ft_putchar(fill);
		return (res);
	}
	while (spec.pad-- > 0)
		ft_putchar(fill);
	wc_putstr(str);
	return (res);
}

int	ft_string(t_spec spec, va_list ap, char **all)
{
	int		res;

	if (spec.letter == 'S' || ft_strncmp(spec.mod, "l", 1) == 0)
		res = big_s(spec, ap);
	else
		res = small_s(spec, ap, all);
	return (res);
}

int	ft_percent(t_spec spec, char c, char **all)
{
	char	fill;
	int		res;

	spec.pad = spec.field_w - 1;
	res = (spec.pad < 0) ? 1 : spec.pad + 1;
	fill = (ft_strchr(spec.flags, '0')) ? 48 : 32;
	if (ft_strchr(spec.flags, '-'))
	{
		fill = 32;
		*all = ft_stradd(*all, c);
		while (spec.pad-- > 0)
			*all = ft_stradd(*all, fill);
		return (res);
	}
	while (spec.pad-- > 0)
		*all = ft_stradd(*all, fill);
	*all = ft_stradd(*all, c);
	return (res);
}
