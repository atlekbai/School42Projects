/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num10.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 21:21:44 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/02/07 21:21:45 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_take_params(intmax_t num, t_desc *l, size_t (*f)(intmax_t))
{
	int	i;

	i = 0;
	if (l->width >= (int)f(num) && l->width >= l->prec)
	{
		if ((int)f(num) > l->prec)
			i += (int)f(num);
		else if (l->prec >= (int)f(num))
			i += l->prec;
	}
	else if (l->prec >= (int)f(num) && l->prec >= l->width)
	{
		if ((int)f(num) > l->width)
			i += (int)f(num);
		else if (l->width >= (int)f(num))
			i += l->width;
	}
	else if ((int)f(num) >= l->width && (int)f(num) >= l->width)
		i += (int)f(num);
	if (num == 0 && (l->prec == -1 || l->prec == 0))
		i--;
	return (i);
}

void	ft_last_action(intmax_t num, t_desc *list, int fd)
{
	if ((list->prec == 0 || list->prec == -1) && num == 0)
		return ;
	else
		ft_putnbr_fd(num, fd);
}

void	ft_num_no_min(intmax_t num, t_desc *list, int sign, int fd)
{
	int tmp;

	tmp = 0;
	if (num < 0)
	{
		sign = 1;
		num = -num;
	}
	if (sign == 1 || ((int)ft_numlen(num) > list->width &&
		(int)ft_numlen(num) > list->prec) || list->flag_plus == 1 ||
		list->flag_space == 1)
		tmp++;
	tmp += ft_take_params(num, list, ft_numlen);
	if (list->flag_zero == 0 || list->prec != -2)
		ft_place_shift_fd(list->width - tmp, fd);
	if (num >= 0 && list->flag_plus == 1 && sign == 0)
		ft_putchar_fd('+', fd);
	else if (sign == 1)
		ft_putchar_fd('-', fd);
	if (list->flag_space == 1 && list->flag_plus == 0 && sign == 0)
		ft_put_space_fd(list, num, fd);
	if (list->flag_zero == 1 && list->prec == -2)
		ft_put_zero_fd(list->width - tmp, fd);
	ft_put_zero_fd(list->prec - (int)ft_numlen(num), fd);
	ft_last_action(num, list, fd);
}

void	ft_num_min(intmax_t num, t_desc *list, int fd)
{
	int	tmp;

	tmp = 0;
	if (num >= 0 && list->flag_plus == 1)
	{
		tmp++;
		ft_putchar_fd('+', fd);
	}
	else if (num < 0)
	{
		tmp++;
		num = -num;
		ft_putchar_fd('-', fd);
	}
	tmp += ft_take_params(num, list, ft_numlen);
	ft_put_zero_fd(list->prec - ft_numlen(num), fd);
	ft_putnbr_fd(num, fd);
	ft_place_shift_fd(list->width - tmp, fd);
}

void	ft_regular_num(t_desc *list, va_list arg, int fd)
{
	intmax_t	num;

	if (list->length == 6)
		num = va_arg(arg, size_t);
	else if (list->length == 5)
		num = va_arg(arg, intmax_t);
	else if (list->length == 4)
		num = va_arg(arg, long long);
	else if (list->length == 3 || list->spec == 'D')
		num = va_arg(arg, long);
	else if (list->length == 2)
		num = (short int)va_arg(arg, int);
	else if (list->length == 1)
		num = (signed char)va_arg(arg, int);
	else
		num = va_arg(arg, int);
	if (list->flag_min == 0)
		ft_num_no_min(num, list, 0, fd);
	else if (list->flag_min == 1)
		ft_num_min(num, list, fd);
}
