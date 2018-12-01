/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:46:26 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/29 12:46:26 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static void		and2(t_byte *acg_split, t_byte **map, t_proc **procs, int64_t i)
{
	int64_t			args[3];

	if (acg_split[0] == DIR_CODE)
		args[0] = ft_args_get(&i, 4, *map);
	else if (acg_split[0] == IND_CODE)
		args[0] = (short)ft_args_get(&i, 2, *map);
	else
		args[0] = (*procs)->reg[(t_byte)ft_args_get(&i, 1, *map) - 1];
	if (acg_split[1] == DIR_CODE)
		args[1] = ft_args_get(&i, 4, *map);
	else if (acg_split[1] == IND_CODE)
		args[1] = (short)ft_args_get(&i, 2, *map);
	else
		args[1] = (*procs)->reg[(t_byte)ft_args_get(&i, 1, *map) - 1];
	args[2] = (t_byte)ft_args_get(&i, 1, *map);
	num_to_reg(procs, args[2] - 1, args[0] & args[1]);
	(*procs)->carry = ((args[0] & args[1]) == 0) ? 1 : 0;
	(*procs)->pc = i + 1;
}

int				and(t_byte **map, t_proc **procs, t_game *game)
{
	t_byte			*acg_split;
	int64_t			i;

	(*game).procs = (*game).procs;
	i = (*procs)->pc;
	acg_split = ft_acg_split((*map)[++i % MEM_SIZE]);
	if (!(validation_xorand(acg_split, procs, map)))
		return (1);
	and2(acg_split, map, procs, i);
	free(acg_split);
	violin(game, 4);
	return (1);
}
