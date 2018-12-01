/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:46:58 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/29 12:46:58 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static int64_t	get_args_ldi(t_byte **map, t_proc **procs,
							int64_t *i, int64_t *index)
{
	long int		args;
	t_byte			*acg_split;

	acg_split = ft_acg_split((*map)[(*i) % MEM_SIZE]);
	if (acg_split[0] == REG_CODE)
	{
		args = ft_args_get(i, 1, *map);
		args = (*procs)->reg[args - 1];
	}
	else if (acg_split[0] == DIR_CODE)
		args = (short)ft_args_get(i, 2, *map);
	else
	{
		args = (short)ft_args_get(i, 2, *map);
		(*index) = (((int)args % IDX_MOD) + (*procs)->pc) % MEM_SIZE;
		if ((*index) < 0)
			(*index) = MEM_SIZE + (*index);
		args = ft_args_get(index, 4, *map);
	}
	free(acg_split);
	return (args);
}

int				ldi(t_byte **map, t_proc **procs, t_game *game)
{
	t_byte			*acg_split;
	long int		args[3];
	int64_t			i;
	int64_t			index;
	int64_t			temp;

	(*game).procs = (*game).procs;
	i = (*procs)->pc;
	acg_split = ft_acg_split((*map)[++i % MEM_SIZE]);
	if (!(validation_ldi(acg_split, procs, map)))
		return (1);
	index = 0;
	args[0] = get_args_ldi(map, procs, &i, &index);
	args[1] = (acg_split[1] == REG_CODE) ? (*procs)->reg[
			ft_args_get(&i, 1, *map) - 1] : (short)ft_args_get(&i, 2, *map);
	args[2] = ft_args_get(&i, 1, *map);
	index = ((((int)args[0] + (int)args[1]) % IDX_MOD) +
			(*procs)->pc - 1) % MEM_SIZE;
	index = (index < 0) ? MEM_SIZE + index : index;
	temp = ft_args_get(&index, 4, *map);
	num_to_reg(procs, args[2] - 1, temp);
	(*procs)->pc = i + 1;
	free(acg_split);
	violin(game, 11);
	return (1);
}
