/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 14:10:16 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/05 14:10:17 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		*choose_way(int id, t_way *paths, t_node *nodes)
{
	t_way	*chosen;
	t_node	*pat;
	t_node	*cho;
	int		i;
	int		j;

	chosen = paths;
	i = 0;
	j = 0;
	while (paths)
	{
		pat = get_by_id(nodes, paths->way[1]);
		cho = get_by_id(nodes, chosen->way[1]);
		if (pat->visited == 1)
			i++;
		if (paths->dist + id <= chosen->dist)
			choose(&chosen, paths, &id);
		else if (cho->visited == 1 && pat->visited == 0)
			chosen = paths;
		paths = paths->next;
		j++;
	}
	if (i == j)
		return (NULL);
	return (chosen->way);
}

int		ant_out(t_ant *tmp, int *i, t_lem l)
{
	int j;

	j = get_next_way(&tmp->cur, tmp->way, l.nodes);
	if (j == 1 && tmp->end != 1)
	{
		if ((*i)++ != -1 && tmp->cur->start == -1)
			tmp->end = 1;
		(tmp->end && l.l) ? ft_putstr("\x1B[32m") : ft_putstr("\x1B[37m");
		ft_printf("L%d-%s ", tmp->id, tmp->cur->name);
	}
	return (1);
}

void	manage_ants(t_lem l)
{
	t_ant	*tmp;
	int		i;
	int		comb;

	i = 0;
	comb = 0;
	while (!is_ants_at_end(l.ants) && comb++ != -1)
	{
		tmp = l.ants;
		while (tmp)
		{
			if (!tmp->way)
				tmp->way = choose_way(tmp->id, l.paths, l.nodes);
			if (tmp->way)
				ant_out(tmp, &i, l);
			tmp = tmp->next;
		}
		ft_printf("\n");
	}
	if (l.p)
	{
		ft_printf("\n[#white]Moves: %d\n", i);
		ft_printf("[#white]Steps: %d\n", comb);
	}
}

void	print_paths(t_way *paths, t_node *nodes)
{
	t_node	*ad;
	int		j;
	int		i;

	i = 0;
	while (paths)
	{
		ft_printf("Path #%d\n", i + 1);
		ft_printf("Distance: %d\n", paths->dist - 1);
		j = 0;
		while (paths->way[j])
		{
			ad = get_by_id(nodes, paths->way[j++]);
			ft_printf("%s", ad->name);
			if (paths->way[j])
				ft_printf(" --> ");
		}
		ft_printf("\n\n");
		paths = paths->next;
		i++;
	}
}

void	set_visit(t_node **nodes, int vis)
{
	t_node *temp;

	temp = *nodes;
	while (temp)
	{
		temp->visited = vis;
		temp = temp->next;
	}
}
