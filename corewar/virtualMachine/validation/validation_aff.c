/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_aff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:24:49 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/29 13:24:49 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int		check_args(t_byte **map, int64_t i)
{
	t_byte	arg;
	int		res;

	res = 1;
	arg = ft_args_get(&i, 1, *map);
	res = (arg > 0 && arg <= REG_NUMBER) ? 1 : 0;
	return (res);
}

int				validation_aff(t_byte *acg, t_proc **procs, t_byte **map)
{
	int i;

	i = 0;
	if (acg[0] == REG_CODE)
		i++;
	if (i == 1 && check_args(map, (*procs)->pc + 1) == 1)
		return (1);
	i = (*procs)->pc;
	if (acg[0] == 2)
		acg[0] = 4;
	else if (acg[0] == 3)
		acg[0] = 2;
	(*procs)->pc = i + acg[0] + 2;
	return (0);
}
