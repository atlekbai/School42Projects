/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 16:27:49 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/18 16:27:49 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	reset_game(t_game *game)
{
	int		i;
	t_proc	*temp;

	i = 0;
	temp = (*game).procs_arr;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	(*game).cycle_delta = CYCLE_DELTA;
	(*game).cycle_to_die = CYCLE_TO_DIE;
	(*game).i = 0;
	(*game).max_checks = MAX_CHECKS;
	(*game).nbr_live = NBR_LIVE;
	(*game).procs = i;
	g_phase = 0;
	g_limit = 50;
	(*game).ctd = 0;
	return (1);
}

int	init_game(t_game *game)
{
	int	i;

	i = 0;
	(*game).map = init_map();
	(*game).map_color = init_intmap();
	(*game).procs_arr = NULL;
	while (i < MAX_PLAYERS)
		(*game).p[i++].size = -1;
	i = -1;
	while (++i < MAX_PLAYERS)
		(*game).player_ids[i] = 0;
	(*game).vis = 0;
	(*game).vis_n = 0;
	(*game).dump = 0;
	(*game).dump_n = 0;
	(*game).aff = 0;
	(*game).over = 0;
	(*game).audio = 0;
	(*game).last_player = -1;
	i = -1;
	while (++i < MEM_SIZE)
		(*game).aff_arr[i] = 0;
	return (1);
}

int	load_game(t_game *game, int ac, char *file, int i)
{
	t_code		code;
	int			pos;

	code = read_cor(file);
	pos = (MEM_SIZE / ac) * (i);
	(*game).p[i] = create_player(code, (*game).player_ids[i]);
	(*game).procs_arr = add_proc((*game).procs_arr, pos, i);
	num_to_reg(&(*game).procs_arr, 0, (*game).player_ids[i]);
	(*game).procs_arr->r1 = (*game).player_ids[i];
	(*game).map = load_player((*game).map, (*game).p[i], pos);
	(*game).pos = MEM_SIZE / ac;
	return (1);
}

int	set_cmd(t_game *game, t_op *ops, t_proc **tp)
{
	if ((*game).i == 0 && (*tp)->cycles < 0)
	{
		(*tp)->cycles = ops[(*game).map[(*tp)->pc] - 1].cycles;
		(*tp)->cmd = (*game).map[(*tp)->pc];
	}
	else if ((*tp)->cycles < 0 || (*tp)->cmd == 0)
	{
		(*tp)->cycles = ops[(*game).map[(*tp)->pc] - 1].cycles - 1;
		(*tp)->cmd = (*game).map[(*tp)->pc];
	}
	return (1);
}

int	action(t_op *ops, t_proc **proc, t_game *game)
{
	t_byte	*tmap;
	t_proc	*tp;

	tmap = (*game).map;
	tp = *proc;
	if ((tmap[tp->pc] > 0 && tmap[tp->pc] <= 16) || tp->cmd != 0)
	{
		set_cmd(game, ops, &tp);
		if (tp->cycles-- <= 0)
		{
			((*game).vis) ? check_bold(&game, tp) : NULL;
			ops[tp->cmd - 1].f(&(game->map), proc, game);
			tp->cmd = 0;
		}
		if (tp->cycles % 60 == 0 && (*game).vis)
			check_last_bold(&game, tp);
	}
	else if ((tp->cycles == -1 && tp->cmd == 0)
			|| (tp->cmd == 0 && tp->cycles > 0))
		tp->pc++;
	tp->pc = tp->pc % MEM_SIZE;
	tp->pc = (tp->pc < 0) ? MEM_SIZE + tp->pc : tp->pc;
	tp->cur_cmd = tmap[tp->pc];
	return (1);
}
