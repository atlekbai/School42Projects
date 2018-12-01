/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:32:11 by ovirchen          #+#    #+#             */
/*   Updated: 2018/05/14 17:32:12 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	init_colors(void)
{
	initscr();
	curs_set(0);
	start_color();
	noecho();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_GREEN);
	init_pair(6, COLOR_BLACK, COLOR_BLUE);
	init_pair(7, COLOR_BLACK, COLOR_RED);
	init_pair(8, COLOR_BLACK, COLOR_CYAN);
	init_pair(9, COLOR_WHITE, COLOR_GREEN);
	init_pair(10, COLOR_WHITE, COLOR_BLUE);
	init_pair(11, COLOR_WHITE, COLOR_RED);
	init_pair(12, COLOR_WHITE, COLOR_CYAN);
	init_pair(13, COLOR_WHITE, COLOR_WHITE);
	init_pair(14, COLOR_WHITE, COLOR_BLACK);
	init_color(COLOR_WHITE, 400, 400, 400);
}

static void	print_frame(void)
{
	int	x;
	int	y;

	attron(COLOR_PAIR(13));
	y = -1;
	while (++y <= Y1 + Y2)
		mvaddstr(0, y, "*");
	x = 0;
	while (++x < X1)
	{
		mvaddstr(x, 0, "*");
		mvaddstr(x, Y1, "*");
		mvaddstr(x, Y1 + Y2, "*");
	}
	y = -1;
	while (++y <= Y1 + Y2)
		mvaddstr(X1, y, "*");
	attroff(COLOR_PAIR(13));
}

static void	print_text_con(t_game game, int *i)
{
	int		num;

	mvprintw(*i, Y1 + 3, "Live Breakdown for current period :");
	mvprintw(*i + 3, Y1 + 3, "Live Breakdown for last period :");
	attroff(A_BOLD);
	num = 0;
	while (++num <= 50)
	{
		mvprintw(*i + 1, Y1 + 3 + num, "-");
		mvprintw(*i + 4, Y1 + 3 + num, "-");
	}
	attron(COLOR_PAIR(15) | A_BOLD);
	mvprintw(*i + 1, Y1 + 3, "[");
	mvprintw(*i + 4, Y1 + 3, "[");
	mvprintw(*i + 1, Y1 + 3 + num, "]");
	mvprintw(*i + 4, Y1 + 3 + num, "]");
	color_set(14, NULL);
	mvprintw(*i + 6, Y1 + 3, "CYCLE_TO_DIE : %d", 0);
	mvprintw(*i + 8, Y1 + 3, "CYCLE_DELTA : %d", game.cycle_delta);
	mvprintw(*i + 10, Y1 + 3, "NBR_LIVE : %d", game.nbr_live);
	mvprintw(*i + 12, Y1 + 3, "MAX_CHECKS : %d", game.max_checks);
	attroff(A_BOLD);
}

void		print_text(t_game game)
{
	int		i;
	int		num;

	init_colors();
	print_frame();
	attron(COLOR_PAIR(14) | A_BOLD);
	mvprintw(2, Y1 + 3, "** PAUSED **");
	mvprintw(4, Y1 + 3, "Cycles/second limit : %d", 50);
	mvprintw(7, Y1 + 3, "Cycle : %d", 0);
	mvprintw(9, Y1 + 3, "Processes : %d", game.procs);
	i = 11;
	num = -1;
	while (game.p[++num].size != -1 && num < MAX_PLAYERS)
	{
		mvprintw(i, Y1 + 3, "Player %d : ", game.p[num].id);
		color_set(num + 1, NULL);
		printw("%s", game.p[num].bot_name);
		color_set(14, NULL);
		mvprintw(++i, Y1 + 5, "Last live : %23d", 0);
		mvprintw(++i, Y1 + 5, "Lives in current period : %9d", 0);
		i += 2;
	}
	print_text_con(game, &i);
}
