/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolkit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:42:35 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/02/23 18:42:36 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_check_width(char *data, t_desc *list)
{
	int	i;
	int	tmp;

	i = 0;
	if ((tmp = ft_last_flag(data)) != -1)
	{
		i = tmp;
		while (data[i] >= '0' && data[i] <= '9')
			i--;
		if (data[i] == '.')
			list->width = 0;
		else
			list->width = ft_printf_atoi(data, tmp);
	}
}

void	ft_put_space_fd(t_desc *list, intmax_t num, int fd)
{
	if (list->prec >= list->width)
		ft_putchar_fd(' ', fd);
	else if ((int)ft_numlen(num) > list->prec &&
		(int)ft_numlen(num) > list->width)
		ft_putchar_fd(' ', fd);
	else if ((list->width > list->prec) && (list->width > (int)ft_numlen(num)))
		ft_putchar_fd(' ', fd);
}

void	ft_n_check(va_list arg)
{
	int	*c;

	c = va_arg(arg, int*);
	*c = g_counter;
}
