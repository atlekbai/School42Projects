/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:46:09 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/29 12:46:10 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int			zjmp(t_byte **map, t_proc **procs, t_game *game)
{
	short	arg;
	int64_t	i;
	t_op	*ops;

	(*game).procs = (*game).procs;
	ops = command_struct();
	i = (*procs)->pc;
	arg = ft_args_get(&i, 2, *map);
	if ((*procs)->carry)
		(*procs)->pc += (int)arg % IDX_MOD;
	else
		(*procs)->pc = i + 1;
	(*procs)->pc = (*procs)->pc % MEM_SIZE;
	if ((*procs)->pc < 0)
		(*procs)->pc = MEM_SIZE + (*procs)->pc;
	free(ops);
	violin(game, 13);
	return (1);
}
