/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:16:50 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/30 16:16:51 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "header.h"

int		check(t_point *point, int size)
{
	int k;

	k = -1;
	while (++k < 4)
		if (point[k].y >= size || point[k].x >= size)
			return (0);
	return (1);
}

char	**map_init(char **map, int size)
{
	int i;
	int j;

	i = -1;
	map = (char **)malloc(sizeof(char *) * (size + 1));
	while (++i < size)
	{
		j = -1;
		map[i] = (char *)malloc(sizeof(char ) * (size + 1));
		while (++j < size)
			map[i][j] = '.';
		map[i][j] = '\0';
	}
	map[i] = 0;
	return (map);
}

int		to_map(char **map, t_point *point, int size, int k)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (((point[k].x == i && point[k].y == j && map[i][j] != '.') ||
				(point[k].x >= size || point[k].y >= size)) && k < 4)
				return (0);
			else if (point[k].x == i && point[k].y == j
					&& map[i][j] == '.' && k < 4)
				k++;
		}
	}
	return (1);
}

char	**place_to_map(t_point *point, char **map, int size, char c)
{
	int i;
	int j;
	int k;
	int t;

	t = 1;
	i = -1;
	k = 0;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			if (to_map(map, point, size, k) == 1)
				if (point[k].x == i && point[k].y == j && k++ < 4)
					map[i][j] = c;
	}
	return (map);
}

char	**map_pop(char **map, int size, char c)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (map[i][j] == c)
				map[i][j] = '.';
		}
	}
	return (map);
}
