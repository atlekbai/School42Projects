/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 21:23:50 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/02/07 21:23:55 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_zeroing_un(char *data, t_desc *list)
{
	char	*str;

	if (list->prec > (int)ft_strlen(data))
	{
		str = ft_place_zero(list->prec - ft_strlen(data));
		data = ft_strjoin(str, data);
	}
	if (list->flag_zero == 1 && list->width > (int)ft_strlen(data) &&
		list->flag_min == 0 && list->prec == -2)
	{
		str = ft_place_zero(list->width - ft_strlen(data));
		data = ft_strjoin(str, data);
	}
	return (data);
}

void	ft_unsigned_check(t_desc *l, va_list arg, int fd)
{
	char	*data;

	if (l->length == 6)
		data = ft_itoa_base(va_arg(arg, size_t), l, 10);
	else if (l->length == 5)
		data = ft_itoa_base(va_arg(arg, uintmax_t), l, 10);
	else if (l->length == 4)
		data = ft_itoa_base(va_arg(arg, unsigned long long), l, 10);
	else if (l->length == 3 || l->spec == 'U')
		data = ft_itoa_base(va_arg(arg, unsigned long), l, 10);
	else if (l->length == 2)
		data = ft_itoa_base((unsigned short)va_arg(arg, unsigned int), l, 10);
	else if (l->length == 1)
		data = ft_itoa_base((unsigned char)va_arg(arg, unsigned int), l, 10);
	else
		data = ft_itoa_base(va_arg(arg, unsigned int), l, 10);
	if ((l->prec == 0 || l->prec == -1) && ft_check_content(data) != 1)
		data = "\0";
	data = ft_zeroing_un(data, l);
	ft_flag_set_fd(data, l, fd);
	if (ft_check_content(data) != 0)
		ft_strdel(&data);
}
