/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:46:21 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/29 12:46:21 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int			live(t_byte **map, t_proc **procs, t_game *game)
{
	unsigned int	arg;
	int				p_id;
	int64_t			i;

	i = (*procs)->pc;
	arg = ft_args_get(&i, 4, *map);
	(*procs)->nbr_live++;
	p_id = get_player_by_id((*game).p, arg);
	if (p_id >= 0)
	{
		(*game).p[p_id].lives_cur++;
		(*game).p[p_id].last_live = (*game).i;
		(*game).last_player = p_id;
	}
	(*procs)->pc = i + 1;
	return (1);
}
