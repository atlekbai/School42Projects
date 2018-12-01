/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:45:49 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/29 12:45:50 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int			ld(t_byte **map, t_proc **procs, t_game *game)
{
	t_byte			*acg_split;
	int64_t			args[3];
	int64_t			i;
	int64_t			index;

	(*game).procs = (*game).procs;
	i = (*procs)->pc;
	acg_split = ft_acg_split((*map)[++i % MEM_SIZE]);
	if (!(validation_ld(acg_split, procs, map)))
		return (1);
	args[0] = (acg_split[0] == DIR_CODE) ?
		ft_args_get(&i, 4, *map) : (short)ft_args_get(&i, 2, *map);
	args[1] = (t_byte)ft_args_get(&i, 1, *map);
	if (acg_split[0] == IND_CODE)
	{
		index = ((*procs)->pc + ((int)args[0] % IDX_MOD) - 1) % MEM_SIZE;
		args[0] = ft_args_get(&index, 4, *map);
	}
	num_to_reg(procs, args[1] - 1, args[0]);
	(*procs)->carry = ((*procs)->reg[args[1] - 1] == 0) ? 1 : 0;
	(*procs)->pc = i + 1;
	free(acg_split);
	violin(game, 9);
	return (1);
}
