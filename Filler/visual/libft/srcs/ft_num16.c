/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num16.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 21:22:17 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/02/07 21:22:24 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_place_hash(char *d, t_desc *list)
{
	char	*tmp;

	tmp = d;
	d = ft_strjoin("0X", tmp);
	ft_strdel(&tmp);
	if (list->spec == 'x')
		d = ft_lower_case(d);
	return (d);
}

int		ft_check_content(char *data)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (data[i])
	{
		if ((data[i] >= '1' && data[i] <= '9') ||
			(data[i] >= 'a' && data[i] <= 'f'))
			num = 1;
		i++;
	}
	return (num);
}

char	*ft_zeroing(char *data, t_desc *list)
{
	char	*str;
	int		tmp;

	tmp = 0;
	if (list->flag_hash == 1 && (list->spec == 'X' || list->spec == 'x'))
		tmp = 2;
	if (list->prec > (int)ft_strlen(data))
	{
		str = ft_place_zero(list->prec - ft_strlen(data));
		data = ft_strjoin(str, data);
		ft_strdel(&str);
	}
	if (list->flag_zero == 1 && list->width > (int)ft_strlen(data) &&
		list->flag_min == 0 && list->prec == -2)
	{
		str = ft_place_zero(list->width - ft_strlen(data) - tmp);
		data = ft_strjoin(str, data);
		ft_strdel(&str);
	}
	if ((list->flag_hash == 1 && ft_check_content(data) == 1))
		data = ft_place_hash(data, list);
	return (data);
}

void	ft_base_16(t_desc *list, va_list arg, int fd)
{
	char	*data;

	if (list->length == 6)
		data = ft_itoa_base(va_arg(arg, size_t), list, 16);
	else if (list->length == 5)
		data = ft_itoa_base(va_arg(arg, uintmax_t), list, 16);
	else if (list->length == 4)
		data = ft_itoa_base(va_arg(arg, unsigned long long), list, 16);
	else if (list->length == 3)
		data = ft_itoa_base(va_arg(arg, unsigned long), list, 16);
	else if (list->length == 2)
		data = ft_itoa_base((unsigned short)va_arg(arg, unsigned), list, 16);
	else if (list->length == 1)
		data = ft_itoa_base((unsigned char)va_arg(arg, unsigned), list, 16);
	else
		data = ft_itoa_base(va_arg(arg, unsigned int), list, 16);
	if ((list->prec == 0 || list->prec == -1) && ft_check_content(data) != 1)
		data = "\0";
	data = ft_zeroing(data, list);
	ft_flag_set_fd(data, list, fd);
	ft_strdel_16(data);
}
