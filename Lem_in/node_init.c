/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:47:40 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/01 12:47:41 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check_node(t_node *nodes, t_node *new)
{
	if (new->x < 0 || new->y < 0)
		ft_err();
	while (nodes)
	{
		if (ft_strequ(nodes->name, new->name))
			ft_err();
		if (nodes->x == new->x && nodes->y == new->y)
			ft_err();
		nodes = nodes->next;
	}
	return (1);
}

static void	check_start_kids(t_node *nodes)
{
	t_node *start;

	start = get_by_start(nodes, 1);
	if (!(start->kids))
		ft_err();
}

t_node		*node_new(t_node *nodes, t_info info)
{
	t_node *new;

	new = (t_node *)malloc(sizeof(t_node));
	new->visited = 0;
	new->used = 0;
	new->parent = NULL;
	new->id = info.id;
	new->start = info.start;
	new->name = ft_strdup(info.name);
	new->x = info.x;
	new->y = info.y;
	new->kids = 0;
	new->way = 0;
	new->distance = MAX;
	if (nodes && check_node(nodes, new))
	{
		new->next = nodes;
		nodes = new;
	}
	else
	{
		new->next = NULL;
		nodes = new;
	}
	return (nodes);
}

void		node_fill(t_node **nodes, char **line, char **cat)
{
	int		ret;
	int		i_s[2];
	t_info	info;

	i_s[0] = 1;
	i_s[1] = 0;
	info = info_def();
	while ((ret = get_next_line(0, line)) == 1)
	{
		if (ft_strequ(*line, "##start") || ft_strequ(*line, "##end"))
			i_s[1] = ft_start(i_s[1], line);
		else if (!ft_strncmp(*line, "L", 1))
			ft_err();
		else if (ft_strcount(*line, 32) == 2 && !ft_strcount(*line, '-'))
			node_proc(line, i_s, info, nodes);
		else if (ft_strcount(*line, '-'))
			break ;
		else if (ft_strncmp(*line, "#", 1) != 0)
			ft_err();
		ft_out(cat, line);
	}
	if (ret != 1 || i_s[1] != 0)
		ft_err();
}

void		node_routes(t_node **nodes, char **line, char **cat)
{
	char *f;
	char *s;

	f = 0;
	s = 0;
	ft_bridge(f, s, nodes, line);
	ft_out(cat, line);
	while (get_next_line(0, line) == 1)
	{
		if (!ft_strncmp(*line, "#", 1))
		{
			ft_out(cat, line);
			continue ;
		}
		else if (ft_strcount(*line, '-'))
			ft_bridge(f, s, nodes, line);
		else
			ft_err();
		ft_out(cat, line);
	}
	check_start_kids(*nodes);
}
