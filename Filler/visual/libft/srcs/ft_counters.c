/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_counters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 21:26:04 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/02/07 21:26:06 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_numlen(intmax_t nb)
{
	size_t	i;

	i = 1;
	while ((nb / 10))
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void	ft_flag_set_fd(char *d, t_desc *list, int fd)
{
	if (list->flag_min == 1 && list->width > (int)ft_strlen(d))
	{
		ft_putstr_fd(d, fd);
		ft_place_shift_fd(list->width - ft_strlen(d), fd);
	}
	else if (list->flag_min == 0 && list->width != 0 &&
		list->width > (int)ft_strlen(d))
	{
		ft_place_shift_fd(list->width - ft_strlen(d), fd);
		ft_putstr_fd(d, fd);
	}
	else
		ft_putstr_fd(d, fd);
}

void	ft_check_star(char *data, t_desc *list, va_list arg, int tmp)
{
	int	i;

	i = -1;
	while (data[++i])
	{
		if (data[i] == '*')
		{
			tmp = va_arg(arg, int);
			if (data[i - 1] != '.' && (data[i + 1] < '0' || data[i + 1] > '9'))
				list->width = tmp;
			else if (data[i - 1] == '.' && (data[i + 1] < '0' ||
				data[i + 1] > '9'))
			{
				list->prec = tmp;
				if (list->prec < 0)
					list->prec = -2;
			}
		}
	}
	if (list->width < 0)
	{
		list->flag_min = 1;
		list->width = -list->width;
	}
}
