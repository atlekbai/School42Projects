/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_ld.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:24:58 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/29 13:24:58 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int		check_args(t_byte *acg, t_byte **map, int64_t i)
{
	int64_t	args[3];
	int		res;

	res = 1;
	i += (acg[0] == DIR_CODE) ? 4 : 2;
	args[1] = (t_byte)ft_args_get(&i, 1, *map);
	res = (args[1] > 0 && args[1] <= REG_NUMBER) ? 1 : 0;
	return (res);
}

int				validation_ld(t_byte *acg, t_proc **procs, t_byte **map)
{
	int i;

	i = 0;
	if (acg[0] == DIR_CODE || acg[0] == IND_CODE)
		i++;
	if (acg[1] == T_REG)
		i++;
	if (acg[2] == 0)
		i++;
	if (i == 3 && check_args(acg, map, (*procs)->pc + 1) == 1)
		return (1);
	i = (*procs)->pc;
	if (acg[0] == 2)
		acg[0] = 4;
	else if (acg[0] == 3)
		acg[0] = 2;
	if (acg[1] == 2)
		acg[1] = 4;
	else if (acg[1] == 3)
		acg[1] = 2;
	(*procs)->pc = i + acg[0] + acg[1] + 2;
	free(acg);
	return (0);
}
