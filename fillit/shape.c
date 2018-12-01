/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:47:26 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/26 20:47:26 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "header.h"

t_point	*get_shape(int **shape)
{
	int		i;
	int		j;
	int		b;
	t_point	*points;

	points = (t_point *)malloc(sizeof(t_point) * 4);
	i = -1;
	b = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (shape[i][j] == 1)
			{
				points[b].x = i;
				points[b++].y = j;
			}
	}
	return (points);
}

t_point	*reshape(t_point *points, int x1, int y1)
{
	int *x;
	int *y;
	int i;

	x = (int *)malloc(sizeof(int) * 4);
	y = (int *)malloc(sizeof(int) * 4);
	i = -1;
	while (++i < 4)
	{
		x[i] = points[i].x;
		y[i] = points[i].y;
	}
	i = -1;
	while (++i < 4)
	{
		points[i].x = points[i].x - ft_min(x, 4) + x1;
		points[i].y = points[i].y - ft_min(y, 4) + y1;
	}
	return (points);
}
