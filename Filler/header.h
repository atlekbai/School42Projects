/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 22:12:54 by atlekbai          #+#    #+#             */
/*   Updated: 2018/04/20 22:12:54 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_map
{
	int		x;
	int		y;
	char	**map;
}				t_map;

typedef	struct	s_point
{
	int		x;
	int		y;
	int		last;
	char	c;
}				t_point;

void			make_decision(t_map map, t_map piece, int p_id);
int				get_ngbrs(t_point point, int **int_map, t_map map);
int				**heat_map(int **int_map, t_map map, t_point *demons);
int				**empty_map(t_map map);
int				mnht(t_point p1, t_point p2);
t_point			*get_units(t_map map, char c);
void			calibr_init(int *max, int *i, t_point *p_max, char c);
t_point			init_point(t_point point, int x, int y, char c);
void			place_ok_init(char *e, int *p, int *i, char c);

#endif
