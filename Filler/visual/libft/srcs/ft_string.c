/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 21:36:25 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/02/07 21:36:27 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_zeroing_string(char *data, t_desc *list)
{
	char	*str;

	if (list->flag_zero == 1 && list->width > (int)ft_strlen(data) &&
		list->flag_min == 0 && list->prec != 2)
	{
		str = ft_place_zero(list->width - ft_strlen(data));
		data = ft_strjoin(str, data);
		ft_strdel(&str);
	}
	return (data);
}

char	*ft_makestr_prec(char *str, t_desc *list)
{
	char	*tmp;

	if (list->prec == -1)
		return ("\0");
	if (list->prec < (int)ft_strlen(str))
	{
		tmp = str;
		str = ft_strsub(str, 0, list->prec);
		ft_strdel(&tmp);
	}
	return (str);
}

void	ft_uni_string(t_desc *list, va_list arg, int fd)
{
	wchar_t	*data;

	data = va_arg(arg, wchar_t*);
	if (data == NULL)
	{
		ft_wchar_null("(null)", list, fd);
		return ;
	}
	else if (list->prec == -1)
	{
		ft_wchar_null("\0", list, fd);
		return ;
	}
	else
		ft_go_wstr(list, data, fd);
}

void	ft_putstr_check(t_desc *list, va_list arg, int fd)
{
	char	*data;

	if (list->length == 3 || list->spec == 'S')
	{
		ft_uni_string(list, arg, fd);
		return ;
	}
	else
		data = va_arg(arg, char*);
	if (data == NULL)
		data = "(null)";
	if (list->prec != -2)
		data = ft_makestr_prec(data, list);
	data = ft_zeroing_string(data, list);
	ft_flag_set_fd(data, list, fd);
}
