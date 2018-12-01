/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:52:08 by atlekbai          #+#    #+#             */
/*   Updated: 2018/04/25 14:10:52 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_map	map_size(char **line)
{
	t_map	map;

	map.x = ft_atoi(ft_strchr(*line, 32) + 1);
	map.y = ft_atoi(ft_strchr(ft_strchr(*line, 32) + 1, 32) + 1);
	return (map);
}

t_point	init_point(t_point point, int x, int y, char c)
{
	point.x = x;
	point.y = y;
	point.c = c;
	return (point);
}

char	**get_map(char **line, t_map map)
{
	char	**net;
	int		i_net;

	i_net = 0;
	get_next_line(0, line);
	net = (char **)malloc(sizeof(char *) * (map.x + 1));
	while (get_next_line(0, line))
	{
		if (ft_atoi(*line) + 1 == map.x)
		{
			*line = ft_strchr(*line, 32) + 1;
			net[i_net++] = *line;
			break ;
		}
		*line = ft_strchr(*line, 32) + 1;
		net[i_net++] = *line;
	}
	net[i_net] = 0;
	get_next_line(0, line);
	return (net);
}

char	**get_piece(char **line, t_map piece)
{
	char	**pie;
	int		i_pie;

	i_pie = 0;
	pie = (char **)malloc(sizeof(char *) * (piece.x + 1));
	while (get_next_line(0, line))
	{
		pie[i_pie] = *line;
		i_pie++;
		if (i_pie == piece.x)
			break ;
	}
	pie[i_pie] = 0;
	return (pie);
}

int		main(void)
{
	char	*line;
	int		p_id;
	t_map	map;
	t_map	piece;

	if (get_next_line(0, &line))
		p_id = ft_atoi(ft_strchr(line, 'p') + 1);
	while (get_next_line(0, &line))
	{
		map = map_size(&line);
		map.map = get_map(&line, map);
		piece = map_size(&line);
		piece.map = get_piece(&line, piece);
		make_decision(map, piece, p_id);
	}
	return (0);
}
