/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 12:53:41 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/16 12:53:42 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_proc		*create_proc(int pc, int id)
{
	int		i;
	t_proc	*proc;

	proc = (t_proc *)malloc(sizeof(t_proc));
	proc->id = id;
	proc->pc = pc;
	proc->alive = 1;
	proc->cycles = -1;
	proc->nbr_live = 0;
	proc->cmd = 0;
	proc->carry = 0;
	proc->r1 = 0;
	proc->next = NULL;
	i = -1;
	while (++i < 16)
		proc->reg[i] = 0;
	return (proc);
}

t_proc		*add_proc(t_proc *proc, int pc, int id)
{
	t_proc	*new;

	new = create_proc(pc, id);
	if (!proc)
		return (new);
	new->next = proc;
	proc = new;
	return (proc);
}

int			check_procs_nbr(t_game *game, int id)
{
	t_proc	*temp;
	int		sum;
	int		i;

	i = 0;
	sum = 0;
	temp = (*game).procs_arr;
	while (temp)
	{
		if (temp->alive && temp->r1 == (*game).player_ids[id])
			sum += temp->nbr_live;
		temp = temp->next;
	}
	if (sum >= (*game).nbr_live)
	{
		(*game).cycle_to_die -= (*game).cycle_delta;
		(*game).max_checks = MAX_CHECKS;
		return (1);
	}
	return (0);
}

static void	check_additional(t_game *game, int s)
{
	t_proc	*temp;
	int		i;

	i = 0;
	while ((*game).p[s].size != -1 && s < MAX_PLAYERS)
	{
		i = (!i && check_procs_nbr(game, s)) ? 1 : i;
		(*game).p[s++].lives_cur = 0;
	}
	temp = (*game).procs_arr;
	while (temp)
	{
		if (temp->alive)
		{
			if (temp->nbr_live < 1)
			{
				temp->alive = 0;
				(*game).procs--;
				((*game).vis && (*game).i >= (*game).vis_n) ?
				system("afplay sounds/08720.mp3&") : 0;
			}
			temp->nbr_live = 0;
		}
		temp = temp->next;
	}
}

int			check_processes(t_game *game)
{
	int			s;

	s = 0;
	check_additional(game, s);
	if ((*game).max_checks == 0)
	{
		(*game).cycle_to_die -= (*game).cycle_delta;
		(*game).max_checks = MAX_CHECKS;
	}
	if ((*game).procs <= 0 || (*game).cycle_to_die <= 0)
		(*game).over = 1;
	(*game).max_checks--;
	return (1);
}
