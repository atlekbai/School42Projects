/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:33:53 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/26 16:35:15 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "header.h"
#include <stdio.h>

void	print_arr(char **map, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ft_putchar(map[i][j]);
		ft_putchar('\n');
	}
}

t_point	**set_points(t_map field)
{
	int		i;
	t_point	**points;

	i = -1;
	points = (t_point **)malloc(sizeof(t_point *) * field.count);
	while (++i < field.count)
		points[i] = reshape(get_shape(field.map[i]), 0, 0);
	return (points);
}

void	set_param(t_param *p1, t_param p2)
{
	(*p1).c = p2.c + 1;
	(*p1).i = p2.i + 1;
	(*p1).all = p2.all;
}

int		fillit(char ***map, int size, t_point **points, t_param par)
{
	t_point	*point;
	int		i;
	int		j;
	t_param temp;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			point = reshape(points[par.i], i, j);
			if (check(point, size) == 1 && to_map(*map, point, size, 0))
			{
				*map = place_to_map(point, *map, size, par.c);
				set_param(&temp, par);
				if (par.i + 1 == par.all || fillit(map, size, points, temp))
					return (1);
				else
					*map = map_pop(*map, size, par.c);
			}
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_point	**points;
	t_map	field;
	char	**map;
	int		size;
	t_param	par;

	map = NULL;
	if (argc == 2)
	{
		field = ft_open(argv);
		par.c = 'A';
		par.i = 0;
		par.all = field.count;
		points = set_points(field);
		size = 2;
		map = map_init(map, size);
		while (!fillit(&map, size, points, par))
			map = map_init(map, ++size);
		print_arr(map, size);
	}
	else if (argc == 1)
		ft_putstr("Usage: ./fillit file_name\n");
	else if (argc > 2)
		ft_error();
	return (0);
}
