/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:36:15 by atlekbai          #+#    #+#             */
/*   Updated: 2018/04/27 17:39:09 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	check_node(t_node *node)
{
	int s;
	int e;

	s = 0;
	e = 0;
	while (node)
	{
		if (node->start == 1)
			s++;
		if (node->start == -1)
			e++;
		node = node->next;
	}
	if (s != 1 || e != 1)
		ft_err();
}

static int	init_lemin(t_lem *l)
{
	(*l).nodes = NULL;
	(*l).cat = ft_strnew(0);
	(*l).l = 0;
	(*l).ways = 0;
	(*l).i = -1;
	(*l).p = 0;
	(*l).paths = NULL;
	return (1);
}

static int	ants_go(t_lem l, int ac, char **av)
{
	int i;

	i = 0;
	l.l = 0;
	while (++i < ac)
	{
		if (ft_strequ("-p", av[i]))
			l.p = 1;
		else if (ft_strequ("-e", av[i]))
			l.l = 1;
	}
	if (l.p)
		print_paths(l.paths, l.nodes);
	set_visit(&(l.nodes), 0);
	l.i = -1;
	while (++(l.i) < l.ant)
		l.ants = ants_add(l.ants, l.i + 1, get_by_start(l.nodes, 1));
	manage_ants(l);
	return (1);
}

static int	ants_num(t_lem *l)
{
	while (((*l).ret = get_next_line(0, &(*l).line)) == 1)
	{
		if (!ft_strncmp((*l).line, "#", 1))
		{
			ft_out(&(*l).cat, &(*l).line);
			continue;
		}
		(*l).ant = ft_atoi((*l).line);
		if ((*l).ant >= 2147483647)
			ft_err();
		if ((*l).ant <= 0 || !str_is_dgt((*l).line))
			ft_err();
		ft_out(&(*l).cat, &(*l).line);
		break ;
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_lem	l;

	init_lemin(&l);
	ants_num(&l);
	if (l.ret == -1)
		ft_err();
	node_fill(&(l.nodes), &l.line, &l.cat);
	check_node(l.nodes);
	node_routes(&(l.nodes), &l.line, &l.cat);
	find_ways(&(l.nodes), &(l.ways), &(l.l));
	if (l.l == 0)
		ft_err();
	while (++(l.i) < l.l)
		l.paths = add_path(l.paths, l.ways[l.i]);
	ft_putendl(l.cat);
	ants_go(l, ac, av);
	return (0);
}
