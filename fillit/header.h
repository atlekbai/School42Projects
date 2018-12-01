/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:46:36 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/26 20:46:38 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_map
{
	int	count;
	int ***map;
}				t_map;

typedef struct	s_param
{
	int		i;
	int		all;
	char	c;
}				t_param;

t_point			*get_shape(int **shape);
t_point			*reshape(t_point *points, int x1, int y1);
t_map			ft_open(char **argv);
int				check(t_point *point, int size);
char			**map_init(char **map, int size);
int				to_map(char **map, t_point *point, int size, int k);
char			**place_to_map(t_point *point, char **map, int size, char c);
char			**map_pop(char **map, int size, char c);
void			read_count(char buff[], char *str, int *j, t_map *map);
int				*arr_unit(int *arr, char **str);
int				is_valid_char(char c);
void			ft_error(void);
void			touches(int i, char *str, int *c, int *cnt);

#endif
