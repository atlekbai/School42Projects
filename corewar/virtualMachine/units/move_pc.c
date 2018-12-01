/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 13:06:22 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/15 20:12:50 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	print_map_w_procs(t_game **game)
{
	t_proc	*temp;
	t_proc	*loop;
	t_proc	*procs;

	temp = NULL;
	procs = (*game)->procs_arr;
	while (procs)
	{
		temp = add_proc(temp, procs->pc, procs->id);
		temp->alive = procs->alive;
		procs = procs->next;
	}
	loop = temp;
	carriage(game, loop);
	print_map(**game);
	refresh();
	while (loop)
	{
		temp = loop->next;
		free(loop);
		loop = temp;
	}
}

int		*init_intmap(void)
{
	int		i;
	int		*map;

	i = -1;
	map = (int*)malloc(sizeof(int) * MEM_SIZE);
	while (++i < MEM_SIZE)
		map[i] = 0;
	return (map);
}

int		ft_abs(int x)
{
	return ((x < 0) ? -x : x);
}

void	game_over(t_game gm)
{
	int	i;
	int	num;

	i = 11;
	num = -1;
	while (gm.p[++num].size != -1 && num < MAX_PLAYERS)
		i += 4;
	attron(A_BOLD);
	color_set(14, NULL);
	mvprintw(i + 14, Y1 + 3, "The winner is :                               ");
	color_set(gm.last_player + 1, NULL);
	if (gm.last_player == -1)
		mvprintw(i + 14, Y1 + 19, "No winner");
	else
		mvprintw(i + 14, Y1 + 19, "%s", gm.p[ft_abs(gm.last_player)].bot_name);
	color_set(14, NULL);
	mvprintw(i + 16, Y1 + 3, "Press any key to finish");
	attroff(A_BOLD);
	nodelay(stdscr, FALSE);
	getch();
	endwin();
	system("pkill afplay");
}
