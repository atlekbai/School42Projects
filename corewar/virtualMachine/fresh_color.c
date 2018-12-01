/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresh_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 14:02:55 by ovirchen          #+#    #+#             */
/*   Updated: 2018/05/25 14:02:57 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		fresh_carriage(t_game **game)
{
	int		i;

	i = 0;
	while (++i <= MEM_SIZE)
	{
		if ((*game)->map_color[i - 1] > 100)
			(*game)->map_color[i - 1] /= 100;
	}
}

void		fresh_line(t_game game)
{
	int		x;
	int		y;
	int		num;
	int		l;

	num = -1;
	x = 12;
	y = Y1 + 3;
	while (game.p[++num].size != -1 && num < MAX_PLAYERS)
		x += 4;
	color_set(15, NULL);
	l = 50;
	while (l-- > 0 && y < 249)
		mvprintw(x, ++y, "-");
}

void		check_bold(t_game **game, t_proc *proc)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while ((*game)->player_ids[num] != proc->r1 && num < MAX_PLAYERS)
		num++;
	while (++i <= MEM_SIZE)
		if ((*game)->map_color[i - 1] == num + 1 + 20)
			(*game)->map_color[i - 1] += 20;
		else if ((*game)->map_color[i - 1] == num + 1 + 40)
			(*game)->map_color[i - 1] -= 40;
}

void		check_last_bold(t_game **game, t_proc *proc)
{
	int		i;
	int		num;
	int		two;
	int		four;

	i = -1;
	two = 0;
	four = 0;
	num = 0;
	while ((*game)->player_ids[num] != proc->r1 && num < MAX_PLAYERS)
		num++;
	while (++i < MEM_SIZE)
		if ((*game)->map_color[i] == num + 1 + 20 && (two = 1))
			while (++i < MEM_SIZE &&
				(*game)->map_color[i] == num + 1 + 20)
				;
		else if ((*game)->map_color[i] == num + 1 + 40 && (four = 1))
			while (++i < MEM_SIZE &&
				(*game)->map_color[i] == num + 1 + 40)
				;
	if (four == 1 && two != 1 && !(i = 0))
		while (++i < MEM_SIZE)
			if ((*game)->map_color[i] == num + 1 + 40)
				(*game)->map_color[i] -= 40;
}
