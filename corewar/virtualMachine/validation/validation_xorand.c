/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_xorand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:25:25 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/29 13:25:25 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int		check_args(t_byte *acg, t_byte **map, int64_t i)
{
	int64_t	args[3];
	int		res;

	res = 1;
	if (acg[0] == DIR_CODE)
		i += 4;
	else if (acg[0] == IND_CODE)
		i += 2;
	else
	{
		args[0] = (t_byte)ft_args_get(&i, 1, *map);
		res = (args[0] > 0 && args[0] <= REG_NUMBER && res != 0) ? 1 : 0;
	}
	if (acg[1] == DIR_CODE)
		i += 4;
	else if (acg[1] == IND_CODE)
		i += 2;
	else
	{
		args[1] = (t_byte)ft_args_get(&i, 1, *map);
		res = (args[1] > 0 && args[1] <= REG_NUMBER && res != 0) ? 1 : 0;
	}
	args[2] = (t_byte)ft_args_get(&i, 1, *map);
	res = (args[2] > 0 && args[2] <= REG_NUMBER && res != 0) ? 1 : 0;
	return (res);
}

int				meow(t_byte *acg, t_proc **procs)
{
	(*procs)->pc = (*procs)->pc + acg[0] + acg[1] + acg[2] + 2;
	free(acg);
	return (1);
}

int				validation_xorand(t_byte *acg, t_proc **procs, t_byte **map)
{
	int i;

	i = 0;
	if (acg[0] == T_REG || acg[0] == DIR_CODE || acg[0] == IND_CODE)
		i++;
	if (acg[1] == T_REG || acg[1] == DIR_CODE || acg[1] == IND_CODE)
		i++;
	if (acg[2] == T_REG)
		i++;
	if (i == 3 && check_args(acg, map, (*procs)->pc + 1) == 1)
		return (1);
	if (acg[0] == 2)
		acg[0] = 4;
	else if (acg[0] == 3)
		acg[0] = 2;
	if (acg[1] == 2)
		acg[1] = 4;
	else if (acg[1] == 3)
		acg[1] = 2;
	if (acg[2] == 2)
		acg[2] = 4;
	else if (acg[2] == 3)
		acg[2] = 2;
	meow(acg, procs);
	return (0);
}
