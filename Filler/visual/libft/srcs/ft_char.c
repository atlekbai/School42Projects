/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 21:36:31 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/02/07 21:36:32 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putchar_check(t_desc *list, va_list arg, int fd)
{
	int		c;

	c = va_arg(arg, int);
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
	else
		ft_putchar_fd(c, fd);
}
