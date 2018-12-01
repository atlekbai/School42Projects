/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:47:12 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/29 12:47:13 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int			sub(t_byte **map, t_proc **procs, t_game *game)
{
	t_byte		*acg_split;
	long int	args[3];
	int64_t		i;

	(*game).procs = (*game).procs;
	i = (*procs)->pc;
	acg_split = ft_acg_split((*map)[++i % MEM_SIZE]);
	if (!(validation_addsub(acg_split, procs, map)))
		return (1);
	args[0] = ft_args_get(&i, 1, *map);
	args[1] = ft_args_get(&i, 1, *map);
	args[2] = ft_args_get(&i, 1, *map);
	num_to_reg(procs, args[2] - 1, (*procs)->reg[args[0] - 1]
			- (*procs)->reg[args[1] - 1]);
	(*procs)->carry = (*procs)->reg[args[2] - 1] == 0 ? 1 : 0;
	(*procs)->pc = i + 1;
	free(acg_split);
	violin(game, 2);
	return (1);
}
