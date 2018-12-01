/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:45:59 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/29 12:46:00 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int			st(t_byte **map, t_proc **procs, t_game *game)
{
	t_byte			*acg_split;
	int64_t			args[2];
	int64_t			i;

	(*game).procs = (*game).procs;
	i = (*procs)->pc;
	acg_split = ft_acg_split((*map)[++i % MEM_SIZE]);
	if (!(validation_st(acg_split, procs, map)))
		return (1);
	args[0] = ft_args_get(&i, 1, *map);
	if (acg_split[1] == REG_CODE)
		args[1] = (t_byte)ft_args_get(&i, 1, *map);
	else
		args[1] = (short)ft_args_get(&i, 2, *map);
	if (acg_split[1] == IND_CODE)
		num_to_map(game, ((*procs)->pc + ((int)args[1] % IDX_MOD)) % MEM_SIZE,
				(*procs)->reg[args[0] - 1], *procs);
	else
		num_to_reg(procs, args[1] - 1, (*procs)->reg[args[0] - 1]);
	(*procs)->pc = i + 1;
	free(acg_split);
	violin(game, 15);
	return (1);
}
