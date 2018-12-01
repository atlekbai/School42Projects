/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 08:51:33 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/02/28 08:51:44 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_take_p(uintmax_t n, t_desc *l, size_t (*f)(uintmax_t, int))
{
	int	i;

	i = 0;
	if (l->width >= (int)f(n, 16) && l->width >= l->prec)
	{
		if ((int)f(n, 16) > l->prec)
			i += (int)f(n, 16);
		else if (l->prec >= (int)f(n, 16))
			i += l->prec;
	}
	else if (l->prec >= (int)f(n, 16) && l->prec >= l->width)
	{
		if ((int)f(n, 16) > l->width)
			i += (int)f(n, 16);
		else if (l->width >= (int)f(n, 16))
			i += l->width;
	}
	else if ((int)f(n, 16) >= l->width && (int)f(n, 16) >= l->width)
	{
		i += (int)f(n, 16);
	}
	if ((l->prec == -1 || l->prec == 0) && n == 0)
		i--;
	return (i);
}

void	ft_putstr_itoa_base(uintmax_t value, int base, int fd)
{
	char		*itoa;
	char		*box;
	size_t		len;

	box = "0123456789abcdef";
	len = ft_len_num(value, base);
	itoa = ft_strnew(len);
	if (itoa)
	{
		itoa[len] = '\0';
		if (value == 0)
			itoa[0] = '0';
		while (value != 0)
		{
			itoa[--len] = box[(value % base)];
			value = value / base;
		}
	}
	ft_putstr_fd(itoa, fd);
	ft_strdel(&itoa);
	return ;
}

void	ft_pt_no_min(uintmax_t num, t_desc *list, int fd)
{
	int	tmp;

	tmp = 2;
	if ((int)ft_numlen(num) > list->width && (int)ft_numlen(num) > list->prec)
		tmp++;
	tmp += ft_take_p(num, list, ft_len_num);
	if (list->flag_zero == 0 || list->prec != -2)
		ft_place_shift_fd(list->width - tmp, fd);
	if (list->flag_zero == 1 && list->prec == -2)
	{
		ft_putstr_fd("0x", fd);
		ft_put_zero_fd(list->width - tmp, fd);
	}
	else
		ft_putstr_fd("0x", fd);
	ft_put_zero_fd(list->prec - (int)ft_len_num(num, 16), fd);
	if ((list->prec == 0 || list->prec == -1) && num == 0)
		return ;
	else
		ft_putstr_itoa_base(num, 16, fd);
}

void	ft_pt_min(uintmax_t num, t_desc *list, int fd)
{
	int	tmp;

	tmp = 2;
	tmp += ft_take_p(num, list, ft_len_num);
	ft_putstr_fd("0x", fd);
	ft_put_zero_fd(list->prec - ft_len_num(num, 16), fd);
	ft_putstr_itoa_base(num, 16, fd);
	ft_place_shift_fd(list->width - tmp, fd);
}

void	ft_pointer_check(t_desc *list, va_list arg, int fd)
{
	uintmax_t	nb;

	nb = va_arg(arg, size_t);
	if (list->flag_min == 0)
		ft_pt_no_min(nb, list, fd);
	else if (list->flag_min == 1)
		ft_pt_min(nb, list, fd);
}
