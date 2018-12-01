/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 21:21:53 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/02/07 21:22:05 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_zeroing_8(char *data, t_desc *list)
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
	if (list->flag_hash == 1 && data[0] != '0')
		data = ft_strjoin("0", data);
	return (data);
}

void	ft_base_8(t_desc *list, va_list arg, int fd)
{
	char	*data;

	if (list->length == 6)
		data = ft_itoa_base(va_arg(arg, size_t), list, 8);
	else if (list->length == 5)
		data = ft_itoa_base(va_arg(arg, uintmax_t), list, 8);
	else if (list->length == 4)
		data = ft_itoa_base(va_arg(arg, unsigned long long), list, 8);
	else if (list->length == 3 || list->spec == 'O')
		data = ft_itoa_base(va_arg(arg, unsigned long), list, 8);
	else if (list->length == 2)
		data = ft_itoa_base((unsigned short)va_arg(arg, unsigned int), list, 8);
	else if (list->length == 1)
		data = ft_itoa_base((unsigned char)va_arg(arg, unsigned int), list, 8);
	else
		data = ft_itoa_base(va_arg(arg, unsigned int), list, 8);
	if ((list->prec == 0 || list->prec == -1) && ft_printf_atoi(data, 0) == 0)
		data = "\0";
	data = ft_zeroing_8(data, list);
	ft_flag_set_fd(data, list, fd);
	if (ft_check_content(data) != 0)
		ft_strdel(&data);
}
