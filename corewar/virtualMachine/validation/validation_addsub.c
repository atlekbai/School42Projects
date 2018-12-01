/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_addsub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:25:17 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/29 13:25:17 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int		check_args(t_byte **map, int64_t i)
{
	int64_t	args[3];
	int		res;

	res = 1;
	args[0] = ft_args_get(&i, 1, *map);
	res = (args[0] > 0 && args[0] <= REG_NUMBER) ? 1 : 0;
	args[1] = ft_args_get(&i, 1, *map);
	res = (args[1] > 0 && args[1] <= REG_NUMBER && res != 0) ? 1 : 0;
	args[2] = ft_args_get(&i, 1, *map);
	res = (args[2] > 0 && args[2] <= REG_NUMBER && res != 0) ? 1 : 0;
	return (res);
}

int				validation_addsub(t_byte *acg, t_proc **procs, t_byte **map)
{
	int i;

	i = 0;
	if (acg[0] == T_REG && acg[1] == T_REG && acg[2] == T_REG)
		i = 3;
	if (i == 3 && check_args(map, (*procs)->pc + 1) == 1)
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
	if (acg[2] == 2)
		acg[2] = 4;
	else if (acg[2] == 3)
		acg[2] = 2;
	(*procs)->pc = i + acg[0] + acg[1] + acg[2] + 2;
	free(acg);
	return (0);
}
