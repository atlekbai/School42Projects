/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strdel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:58:40 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/01/26 20:35:35 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_strdel_array(char **data)
{
	int		i;

	i = 0;
	while (data[i])
	{
		ft_strdel(&data[i]);
		i++;
	}
	ft_memdel((void*)&data);
}

void		ft_strdel_16(char *data)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	while (data[i])
	{
		if (data[i] != '0' && data[i] != 'x' && data[i] != 'X')
			check = 1;
		i++;
	}
	if (check == 1)
		ft_strdel(&data);
}
