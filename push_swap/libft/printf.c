/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 20:50:10 by atlekbai          #+#    #+#             */
/*   Updated: 2018/04/16 22:22:11 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		magic(t_spec spec, va_list ap, char **str)
{
	int res;

	res = 0;
	if (spec.letter == 'd' || spec.letter == 'i' || spec.letter == 'D')
		res = ft_digit(spec, ap, str);
	else if (spec.letter == 'o' || spec.letter == 'O' || spec.letter == 'u'
		|| spec.letter == 'U')
		res = ft_octal(spec, ap, str);
	else if (spec.letter == 'x' || spec.letter == 'X')
		res = ft_hex(spec, ap, str);
	else if (spec.letter == 'c' || spec.letter == 'C')
		res = ft_char(spec, ap);
	else if (spec.letter == 's' || spec.letter == 'S')
		res = ft_string(spec, ap, str);
	else if (spec.letter == 'p')
	{
		spec.letter = 'p';
		spec.mod = "l";
		res = ft_hex(spec, ap, str);
	}
	else if (spec.letter == '%')
		res = ft_percent(spec, '%', str);
	else if (ft_isalpha(spec.letter))
		res = ft_percent(spec, spec.letter, str);
	return (res);
}

int		process(char *stack, va_list ap, char **str)
{
	t_spec	spec;
	int		res;

	spec.precision = -1;
	spec.field_w = 0;
	res = 0;
	if (ft_dgtchr(stack))
		spec.flags = ft_strsub(stack, 0, ft_dgtchr(stack) - stack);
	if (ft_dgtchr(stack))
		spec.field_w = ABS(ft_atoi(ft_dgtchr(stack)));
	if (ft_strchr(stack, '.'))
	{
		spec.precision = ft_atoi(ft_strchr(stack, '.') + 1);
		spec.prec = 1;
	}
	spec.mod = ft_mod(stack);
	spec.letter = stack[ft_strlen(stack) - 1];
	res = magic(spec, ap, str);
	ft_strdel(&spec.flags);
	ft_strdel(&spec.mod);
	return (res);
}

void	ft_strsub_free(char const *str, char **stack)
{
	char *temp;

	temp = ft_strsub(str, 0, 1);
	*stack = ft_strjoin_free(*stack, temp);
	free(temp);
}

int		bytes_char(char const **str, char *stack, va_list ap)
{
	int		res;
	char	*all;

	res = 0;
	all = ft_strnew(0);
	stack = ft_strsub((*str)++, 0, 0);
	while (**str && (!is_end(**str)) && is_spec(**str))
		ft_strsub_free((*str)++, &stack);
	if (is_end(**str) || ft_isalpha(**str))
		ft_strsub_free(*str, &stack);
	if (*stack && ft_strlen(stack) > 0)
	{
		res += process(stack, ap, &all);
		ft_putstr(all);
	}
	else
	{
		res++;
		ft_putchar(**str);
	}
	ft_strdel(&all);
	ft_strdel(&stack);
	return (res);
}

int		ft_printf(char const *str, ...)
{
	int		res;
	va_list	ap;
	char	*stack;

	res = 0;
	stack = NULL;
	va_start(ap, str);
	while (*str)
	{
		if (ft_strncmp(str, "[#", 2) == 0)
		{
			color_usual(&str);
			color_bold(&str);
		}
		if (*str == '%' && *(str + 1) > 0)
			res += bytes_char(&str, stack, ap);
		else if (*str != '%')
		{
			write(1, str, 1);
			res++;
		}
		str++;
	}
	va_end(ap);
	return (res);
}
