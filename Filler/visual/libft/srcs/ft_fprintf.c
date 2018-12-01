/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:51:41 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/02/07 14:32:37 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnoarg(t_desc *list, int fd)
{
	char	c;

	c = list->spec;
	if (list->flag_min == 1)
	{
		ft_putchar_fd(c, fd);
		ft_place_shift_fd(list->width - 1, fd);
	}
	else if (list->flag_min == 0 && list->flag_zero == 1)
	{
		ft_putstr_fd(ft_place_zero(list->width - 1), fd);
		ft_putchar_fd(c, fd);
	}
	else if (list->flag_min == 0 && list->flag_zero == 0)
	{
		ft_place_shift_fd(list->width - 1, fd);
		ft_putchar_fd(c, fd);
	}
}

void	ft_before_print(t_desc *list, va_list arg, int fd)
{
	if (list->spec == 'd' || list->spec == 'D' || list->spec == 'i')
		ft_regular_num(list, arg, fd);
	else if (list->spec == 'o' || list->spec == 'O')
		ft_base_8(list, arg, fd);
	else if (list->spec == 'x' || list->spec == 'X')
		ft_base_16(list, arg, fd);
	else if (list->spec == 'u' || list->spec == 'U')
		ft_unsigned_check(list, arg, fd);
	else if (list->spec == 's' || list->spec == 'S')
		ft_putstr_check(list, arg, fd);
	else if (list->spec == 'c' || list->spec == 'C')
		ft_putchar_check(list, arg, fd);
	else if (list->spec == 'p')
		ft_pointer_check(list, arg, fd);
	else if (list->spec == 'n')
		ft_n_check(arg);
	else if (list->spec == 'b')
		ft_binary(list, arg, fd);
	else
		ft_putnoarg(list, fd);
}

int		ft_begin(const char *str, int i, va_list ar, int fd)
{
	int		count;
	char	*data;
	t_desc	*list;

	count = 0;
	list = ft_create_new_list();
	data = ft_takestring(str, i, list);
	count += ft_strlen(data);
	ft_check_flag(data, list);
	ft_check_width(data, list);
	ft_check_prec(data, list);
	ft_check_star(data, list, ar, 0);
	ft_check_length(data, list);
	if (list->spec == '\0')
		return (count);
	ft_before_print(list, ar, fd);
	ft_strdel(&data);
	free(list);
	return (count + 1);
}

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;

	i = 0;
	g_counter = 0;
	va_start(arg, format);
	while (format[i] != '\0')
	{
		if (format[i] == '{')
			i += ft_set_color(format, i, 0);
		else if (format[i] == '%')
		{
			i++;
			i += ft_begin(format, i, arg, 1);
			if (format[i] == '\0')
				return (g_counter);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			i++;
		}
	}
	va_end(arg);
	return (g_counter);
}

int		ft_fprintf(int fd, const char *format, ...)
{
	va_list	arg;
	int		i;

	i = 0;
	g_counter = 0;
	va_start(arg, format);
	while (format[i] != '\0')
	{
		if (format[i] == '{')
			i += ft_set_color(format, i, 0);
		else if (format[i] == '%')
		{
			i++;
			i += ft_begin(format, i, arg, fd);
			if (format[i] == '\0')
				return (g_counter);
		}
		else
		{
			ft_putchar_fd(format[i], fd);
			i++;
		}
	}
	va_end(arg);
	return (g_counter);
}
