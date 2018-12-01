/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:46:32 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/29 12:46:32 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int64_t		ind_arg_2(int64_t arg, t_byte **map)
{
	int64_t	res;
	int		f_ind;

	f_ind = (arg % IDX_MOD) % MEM_SIZE;
	res = ((*map)[f_ind] << 24) | ((*map)[f_ind + 1] << 16)
		| ((*map)[f_ind + 2] << 8) | (*map)[f_ind + 3];
	return (res);
}

int64_t		get_index(t_proc **procs, int64_t arg1, int64_t arg2)
{
	int64_t	index;

	index = (*procs)->pc + (((int)arg1 + (int)arg2) % IDX_MOD);
	index = (index < 0) ? MEM_SIZE + (index % MEM_SIZE) : index % MEM_SIZE;
	return (index);
}

int			sti(t_byte **map, t_proc **procs, t_game *game)
{
	t_byte			*acg_split;
	int64_t			args[3];
	int64_t			i;
	int64_t			index;

	i = (*procs)->pc;
	acg_split = ft_acg_split((*map)[++i % MEM_SIZE]);
	if (!(validation_sti(acg_split, procs, &(*game).map)))
		return (1);
	args[0] = (t_byte)ft_args_get(&i, 1, *map);
	if ((violin(game, 14)) && acg_split[1] == REG_CODE)
		args[1] = (*procs)->reg[(int64_t)ft_args_get(&i, 1, *map) - 1];
	else if (acg_split[1] == IND_CODE)
		args[1] = ind_arg_2((short)ft_args_get(&i, 2, *map), map);
	else
		args[1] = (short)ft_args_get(&i, 2, *map);
	if (acg_split[2] == REG_CODE)
		args[2] = (*procs)->reg[(int64_t)ft_args_get(&i, 1, *map) - 1];
	else
		args[2] = (short)ft_args_get(&i, 2, *map);
	index = get_index(procs, args[1], args[2]);
	num_to_map(game, index, (*procs)->reg[args[0] - 1], *procs);
	(*procs)->pc = i + 1;
	free(acg_split);
	return (1);
}
