/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_new_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:20:13 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/02/07 15:20:44 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_desc			*ft_create_new_list(void)
{
	t_desc		*tmp;

	tmp = (t_desc*)malloc(sizeof(t_desc));
	if (tmp)
	{
		tmp->flag_min = 0;
		tmp->flag_plus = 0;
		tmp->flag_space = 0;
		tmp->flag_zero = 0;
		tmp->flag_hash = 0;
		tmp->width = 0;
		tmp->prec = -2;
		tmp->length = 0;
		tmp->spec = '-';
	}
	return (tmp);
}
