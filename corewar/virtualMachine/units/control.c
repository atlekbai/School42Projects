/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 09:23:46 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/30 09:23:46 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void			limit_set(char c)
{
	if (c == 32 && g_phase == 0)
	{
		mvprintw(2, Y1 + 3, "** RUNNING **");
		nodelay(stdscr, TRUE);
		g_phase = 1;
		return ;
	}
	else if (c == 's' || (c == 32 && g_phase != 0))
	{
		mvprintw(2, Y1 + 3, "** PAUSED ** ");
		nodelay(stdscr, FALSE);
		g_phase = 0;
	}
	g_limit -= (c == 'q') ? 10 : 0;
	g_limit -= (c == 'w') ? 1 : 0;
	g_limit += (c == 'e') ? 1 : 0;
	g_limit += (c == 'r') ? 10 : 0;
	g_limit = (g_limit > 1000) ? 1000 : g_limit;
	g_limit = (g_limit < 1) ? 1 : g_limit;
}

static void			press_key(void)
{
	char	c;

	attron(A_BOLD);
	color_set(14, NULL);
	c = getch();
	if (c == 'x')
	{
		endwin();
		system("pkill afplay");
		system("say -v Daniel 'Good bye'&");
		ft_putendl_fd("Good bye!", 2);
		exit(0);
	}
	limit_set(c);
	mvprintw(4, Y1 + 3 + 22, "%u   ", g_limit);
	attroff(A_BOLD);
	if (g_phase == 0 && c != 's')
		press_key();
}

static int			ncurses(t_game **game, int ctd)
{
	print_refresh(**game);
	print_map_w_procs(game);
	if ((*game)->ctd == ctd - 1)
	{
		(*game)->ctd = -1;
		attron(A_BOLD);
		print_liveline(**game, 2);
		fresh_line(**game);
		attroff(A_BOLD);
	}
	return (1);
}

static void			check_time_limit(t_game **game, time_t start, int *gc)
{
	time_t	end;

	if ((*game)->vis && (*game)->i >= (*game)->vis_n)
	{
		(*game)->ctd++;
		time(&end);
		usleep(1000000 / g_limit - 1000 * difftime(end, start));
		press_key();
	}
	(*game)->i++;
	*gc = *gc + 1;
}

void				move_around(t_op *ops, t_game *gm)
{
	t_proc	*temp;
	time_t	start;
	int		ctd;
	int		gc;

	gc = 0;
	while (1)
	{
		time(&start);
		ctd = ((*gm).ctd == 1 || (*gm).ctd == 0) ? (*gm).cycle_to_die : ctd;
		temp = (*gm).procs_arr;
		if (gc % (*gm).cycle_to_die == 0 && (*gm).i != 0
			&& check_processes(gm) && !(gc = 0))
			if ((*gm).over == 1)
				break ;
		while (temp)
		{
			(temp->alive) ? action(ops, &temp, gm) : 0;
			temp = temp->next;
		}
		((*gm).vis && (*gm).i >= (*gm).vis_n) ? ncurses(&gm, ctd) : 0;
		((*gm).dump && (*gm).dump_n == (*gm).i) ? dump_map(*gm) : NULL;
		check_time_limit(&gm, start, &gc);
	}
}
