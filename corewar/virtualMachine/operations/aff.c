/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:45:22 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/29 12:45:23 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int			aff(t_byte **map, t_proc **procs, t_game *game)
{
	int64_t	arg;
	t_byte	*acg_split;
	int64_t	i;

	(*game).procs = (*game).procs;
	i = (*procs)->pc;
	acg_split = ft_acg_split((*map)[++i % MEM_SIZE]);
	if (!(validation_aff(acg_split, procs, map)))
	{
		free(acg_split);
		return (1);
	}
	arg = ft_args_get(&i, 1, *map);
	arg = (*procs)->reg[arg - 1];
	if ((*game).aff != 0)
	{
		(*game).aff_arr[(*game).aff - 1] = arg % 256;
		(*game).aff++;
	}
	(*procs)->pc = i + 1;
	free(acg_split);
	violin(game, 3);
	return (1);
}
