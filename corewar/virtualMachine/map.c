/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 19:02:27 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/15 20:11:52 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	print_digits(t_game **game, int k, int i, int *j)
{
	if ((*game)->p[k].size > 0 && *j < (*game)->p[k].size)
	{
		(*game)->map_color[i - 1] = k + 1;
		color_set((*game)->map_color[i - 1], NULL);
		if ((*game)->map[i - 1] < 16)
			printw("0");
		printw("%x", (*game)->map[i - 1]);
		(*j)++;
	}
	else
	{
		(*game)->map_color[i - 1] = 15 + 20;
		color_set((*game)->map_color[i - 1] - 20, NULL);
		attron(A_BOLD);
		if ((*game)->map[i - 1] < 16)
			printw("0");
		printw("%x", (*game)->map[i - 1]);
		attroff(A_BOLD);
	}
}

void		print_start_map(t_game *game, t_proc *proc)
{
	int		x;
	int		y;
	int		i;
	int		k;
	int		j;

	x = 2;
	y = 3;
	i = 0;
	k = 0;
	j = 0;
	while (++i <= MEM_SIZE)
	{
		move(x, y);
		print_digits(&game, k, i, &j);
		y += 2;
		if (i % game->pos == 0 && !(j = 0))
			k++;
		(i % WIDTH == 0 && (y = 3)) ? ++x : ++y;
	}
	refresh();
}

t_byte		*init_map(void)
{
	int		i;
	t_byte	*map;

	i = -1;
	map = (t_byte *)malloc(sizeof(t_byte) * MEM_SIZE);
	while (++i < MEM_SIZE)
		map[i] = 0;
	return (map);
}

t_byte		*load_player(t_byte *map, t_player p, int pos)
{
	int	i;

	i = 0;
	while (pos < MEM_SIZE && i < p.size)
		map[pos++] = p.exec_code[i++];
	return (map);
}

void		dump_map(t_game game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(game.aff) ? print_aff(game) : NULL;
	while (++i <= MEM_SIZE)
	{
		if (i % 64 == 1)
			(j == 0) ? ft_printf("0x0000 : ") : ft_printf("%#.4x : ", j * 64);
		(game.map[i - 1] < 16) ? ft_putchar('0') : NULL;
		ft_printf("%x", game.map[i - 1]);
		if (i % 64 == 0)
		{
			j++;
			ft_printf("\n");
		}
		else
			ft_putchar(' ');
	}
	exit(0);
}
