/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:29:26 by hdanylev          #+#    #+#             */
/*   Updated: 2018/02/18 15:29:29 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_all	*ft_output(t_all *all)
{
	if (all->lat[5].flag == 1 && all->output[0] == '-')
		write(1, &all->output[1], all->lennumonly - 1);
	else if (all->lat[1].flag == 1 && all->lat[2].flag != 1 &&
			all->output[0] == '-')
		write(1, &all->output[1], all->lennumonly - 1);
	else if (all->spc == 'c' && all->output[0] == '\0')
	{
		all->lennumonly++;
		write(1, "\0", 1);
	}
	else if (all->spc == 'S' && all->up == NULL)
	{
		write(1, "(null)", 6);
		all->len += 6;
	}
	else if (all->output)
		write(1, all->output, all->lennumonly);
	all->len += all->lennumonly;
	all->printed = 1;
	free(all->output);
	return (all);
}
