/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 22:14:22 by atlekbai          #+#    #+#             */
/*   Updated: 2018/04/20 22:14:24 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		place_is_ok(t_point t, t_map map, t_map piece)
{
	int		p;
	int		i;
	int		j;
	char	e;

	place_ok_init(&e, &p, &i, t.c);
	while (++i < piece.x)
	{
		j = -1;
		while (++j < piece.y)
			if (t.x + i < 0 || t.y + j < 0 ||
				t.x + i >= map.x || t.y + j >= map.y)
			{
				if (piece.map[i][j] != '.')
					return (0);
				continue;
			}
			else if ((map.map[t.x + i][t.y + j] == e && piece.map[i][j] != '.'))
				return (0);
			else if (map.map[t.x + i][t.y + j] == t.c && piece.map[i][j] == '*')
				p++;
	}
	if (p == 1)
		return (1);
	return (0);
}

t_point	calibrate(t_point point, t_map map, t_map piece, int **int_map)
{
	t_point	temp;
	t_point	p_max;
	int		i;
	int		j;
	int		max;

	calibr_init(&max, &i, &p_max, point.c);
	p_max = init_point(p_max, 0, 0, point.c);
	while (++i < piece.x * 2 - 1)
	{
		j = -1;
		while (++j < piece.y * 2 - 1 &&
			point.x - i < map.x && point.y - j < map.y)
		{
			temp = init_point(temp, point.x - i, point.y - j, point.c);
			if (get_ngbrs(temp, int_map, map) != -1)
				if (place_is_ok(temp, map, piece) &&
					get_ngbrs(temp, int_map, map) <= max)
				{
					max = get_ngbrs(temp, int_map, map);
					p_max = temp;
				}
		}
	}
	return (p_max);
}

t_point	get_another(t_point *angels, int **int_map, t_map map, t_map piece)
{
	t_point	p_max;
	int		max;
	int		k;

	max = 2147483647;
	k = -1;
	p_max.x = 0;
	p_max.y = 0;
	while (angels[++k].last != 1)
		if (get_ngbrs(angels[k], int_map, map) <= max &&
			get_ngbrs(angels[k], int_map, map) >= 0 &&
			place_is_ok(calibrate(angels[k], map, piece, int_map), map, piece))
		{
			max = get_ngbrs(angels[k], int_map, map);
			p_max = calibrate(angels[k], map, piece, int_map);
		}
	return (p_max);
}

void	place_map(int **int_map, t_point *angels, t_map piece, t_map map)
{
	t_point	p_max;
	int		max;
	int		k;

	p_max = angels[0];
	max = get_ngbrs(p_max, int_map, map);
	k = -1;
	while (angels[++k].last != 1)
		if (get_ngbrs(angels[k], int_map, map) <= max
			&& get_ngbrs(angels[k], int_map, map) >= 0)
		{
			max = get_ngbrs(angels[k], int_map, map);
			p_max = angels[k];
		}
	p_max = calibrate(p_max, map, piece, int_map);
	if (!place_is_ok(p_max, map, piece))
		p_max = get_another(angels, int_map, map, piece);
	ft_printf("%d %d\n", p_max.x, p_max.y);
}

void	make_decision(t_map map, t_map piece, int p_id)
{
	char const	pers[2] = "OX";
	t_point		*angels;
	t_point		*demons;
	int			**int_map;

	angels = get_units(map, pers[p_id - 1]);
	demons = (p_id == 1) ? get_units(map, 'X') : get_units(map, 'O');
	int_map = empty_map(map);
	int_map = heat_map(int_map, map, demons);
	place_map(int_map, angels, piece, map);
	free(angels);
	free(demons);
	free(int_map);
}
