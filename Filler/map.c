/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 23:53:36 by atlekbai          #+#    #+#             */
/*   Updated: 2018/04/22 23:53:37 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_point	*get_units(t_map map, char c)
{
	t_point *points;
	int		i;
	int		j;
	int		k;

	k = 0;
	points = (t_point *)malloc(sizeof(t_point) * (map.x * map.y));
	i = -1;
	while (++i < map.x)
	{
		j = -1;
		while (++j < map.y)
		{
			if (map.map[i][j] == c)
			{
				points[k].x = i;
				points[k].y = j;
				points[k].last = 0;
				points[k].c = c;
				k++;
			}
		}
	}
	points[k].last = 1;
	return (points);
}

int		mnht(t_point p1, t_point p2)
{
	return (ABS(p1.x - p2.x) + ABS(p1.y - p2.y));
}

int		**empty_map(t_map map)
{
	int	**int_map;
	int i;
	int j;

	int_map = (int **)malloc(sizeof(int *) * map.x);
	i = -1;
	while (++i < map.x)
	{
		int_map[i] = (int *)malloc(sizeof(int) * map.y);
		j = -1;
		while (++j < map.y)
		{
			if (map.map[i][j] == 'O')
				int_map[i][j] = -1;
			else if (map.map[i][j] == 'X')
				int_map[i][j] = -2;
			else
				int_map[i][j] = 0;
		}
	}
	return (int_map);
}

int		**heat_map(int **int_map, t_map map, t_point *demons)
{
	t_point	temp;
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < map.x)
	{
		j = -1;
		while (++j < map.y)
		{
			k = -1;
			while (demons[++k].last != 1)
			{
				temp.x = i;
				temp.y = j;
				if (int_map[i][j] > 0 && k > 0 &&
					mnht(temp, demons[k]) < int_map[i][j])
					int_map[i][j] = mnht(temp, demons[k]);
				else if (k == 0 && int_map[i][j] >= 0)
					int_map[i][j] = mnht(temp, demons[k]);
			}
		}
	}
	return (int_map);
}

int		get_ngbrs(t_point point, int **int_map, t_map map)
{
	int *min;
	int i;
	int j;
	int k;

	i = -2;
	k = 0;
	min = (int *)malloc(sizeof(int) * 9);
	while (++i < 2)
	{
		j = -2;
		while (++j < 2)
		{
			if (point.x + i < 0 || point.y + j < 0 ||
				point.x + i >= map.x || point.y + j >= map.y)
				continue;
			if (int_map[point.x + i][point.y + j] > 0)
				min[k++] = int_map[point.x + i][point.y + j];
		}
	}
	if (k == 0)
		return (-1);
	k = ft_min(min, k);
	free(min);
	return (k);
}
