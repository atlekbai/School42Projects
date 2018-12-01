/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:18:52 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/05/07 16:18:53 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_STRUCTS_H
# define FT_SELECT_STRUCTS_H

# include "ft_lib.h"

typedef struct	s_node
{
	char			*name;
	char			*chmod;
	int				select_now;
	int				select;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct	s_out
{
	int				width;
	int				height;
	int				no_size;
	int				size;
	int				index;
	char			search[1024];
	char			*term_name;
	t_node			*begin;
	t_node			*now;
	t_node			*end;
	struct termios	term;
	struct termios	term_backup;
	int				max;
}				t_out;

typedef int		(*t_action) (void);

typedef struct	s_keys
{
	t_action	function;
	long int	value;
}				t_keys;

#endif
