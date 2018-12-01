/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfrk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:45:36 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/29 12:45:36 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int			lfrk(t_byte **map, t_proc **procs, t_game *game)
{
	int64_t			i;
	short			arg;
	int				index;
	t_op			*ops;

	i = (*procs)->pc;
	ops = command_struct();
	arg = ft_args_get(&i, 2, *map);
	index = ((*procs)->pc + (int)arg) % MEM_SIZE;
	if (index < 0)
		index = MEM_SIZE + index;
	(*game).procs_arr = add_proc((*game).procs_arr, index, ++(*game).procs);
	arg = -1;
	while (++arg < 16)
		(*game).procs_arr->reg[arg] = (*procs)->reg[arg];
	(*game).procs_arr->carry = (*procs)->carry;
	(*game).procs_arr->r1 = (*procs)->r1;
	(*game).procs_arr->cur_cmd = (*procs)->cur_cmd;
	(*game).procs_arr->alive = (*procs)->alive;
	(*game).procs_arr->nbr_live = (*procs)->nbr_live;
	(*procs)->pc = i + 1;
	free(ops);
	violin(game, 8);
	return (1);
}
