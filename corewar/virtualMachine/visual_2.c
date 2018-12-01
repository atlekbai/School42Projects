/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:50:57 by ovirchen          #+#    #+#             */
/*   Updated: 2018/05/22 13:51:00 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		carriage(t_game **game, t_proc *proc)
{
	t_proc	*temp;
	int		k;
	int		i;

	i = 0;
	fresh_carriage(game);
	while (++i <= MEM_SIZE)
	{
		temp = (*game)->procs_arr;
		while (temp)
		{
			k = get_player_by_id((*game)->p, temp->r1);
			if (temp && i - 1 == temp->pc && temp->alive)
			{
				if ((*game)->map[i - 1] == 1 && (*game)->map_color[i - 1] < 100)
					(*game)->map_color[i - 1] = (*game)->map_color[i - 1] * 100
						+ k + 1 + 8;
				else if ((*game)->map_color[i - 1] < 100)
					(*game)->map_color[i - 1] = (*game)->map_color[i - 1] * 100
						+ k + 1 + 4;
				proc = proc->next;
			}
			temp = temp->next;
		}
	}
}

void		print_map(t_game game)
{
	int		x;
	int		y;
	int		i;
	int		el;

	x = 2;
	y = 3;
	i = 0;
	while (++i <= MEM_SIZE)
	{
		if ((el = game.map_color[i - 1]) > 100)
			el = el % 100;
		color_set(el % 20, NULL);
		if ((el >= 9 && el <= 12) || (el > 20 && el < 100))
			attron(A_BOLD);
		else
			attroff(A_BOLD);
		move(x, y);
		(game.map[i - 1] < 16) ? printw("0") : 0;
		printw("%x", game.map[i - 1]);
		y += 2;
		(i % WIDTH == 0 && (y = 3)) ? ++x : ++y;
	}
}

void		print_liveline(t_game game, int i)
{
	int		x;
	int		y;
	int		num;
	float	k;
	int		l;

	x = 12;
	num = -1;
	k = 0;
	while (game.p[++num].size != -1 && num < MAX_PLAYERS && (x += 4) > 0)
		k += game.p[num].lives_cur;
	if (k == 0.0)
		return ;
	if (i == 2)
		x += 3;
	num = -1;
	y = Y1 + 3;
	while (game.p[++num].size != -1 && num < MAX_PLAYERS)
		if ((l = game.p[num].lives_cur * 50 / k) > 0)
		{
			color_set(num + 1, NULL);
			while (l-- >= 0 && y < 249)
				mvprintw(x, ++y, "-");
		}
}

void		print_refresh(t_game gm)
{
	int	i;
	int	num;

	color_set(14, NULL);
	attron(A_BOLD);
	mvprintw(4, Y1 + 3 + 22, "%u   ", g_limit);
	mvprintw(7, Y1 + 3 + 8, "%u", gm.i);
	mvprintw(9, Y1 + 3 + 12, "%d     ", gm.procs);
	i = 11;
	num = -1;
	while (gm.p[++num].size != -1 && num < MAX_PLAYERS)
	{
		mvprintw(++i, Y1 + 5 + 12, "%23d", gm.p[num].last_live);
		mvprintw(++i, Y1 + 5 + 26, "%9d", gm.p[num].lives_cur);
		i += 2;
	}
	mvprintw(i + 6, Y1 + 3 + 15, "%d    ", gm.cycle_to_die);
	mvprintw(i + 14, Y1 + 3, "CURRENT WINNER :                               ");
	color_set(gm.last_player + 1, NULL);
	if (gm.last_player >= 0)
		mvprintw(i + 14, Y1 + 20, "%s", gm.p[ft_abs(gm.last_player)].bot_name);
	print_liveline(gm, 1);
	attroff(A_BOLD);
}
