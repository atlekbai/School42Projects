/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:54:00 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/04 16:54:01 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	bfs(t_queue *q)
{
	t_node	*list;
	int		i;

	if (!q)
		return ;
	list = pop_queue(&q);
	list->visited = 1;
	i = -1;
	while (list->kids[++i])
	{
		list->kids[i]->parent = list;
		if (list->kids[i]->visited != 1 && list->kids[i]->used != 1)
			q = add_queue(q, list->kids[i]);
		else if (list->distance > list->kids[i]->distance
					&& list->kids[i]->used != 1)
		{
			list->way = add_way(list->way, list->kids[i]->way, list);
			list->distance = list->kids[i]->distance + 1;
		}
	}
	bfs(q);
}

void	node_distance(t_node **nodes)
{
	t_node	*step;
	t_queue	*q;

	step = get_by_start(*nodes, 1);
	step->distance = 0;
	step->parent = step;
	step->way = add_kid(step->way, step);
	q = NULL;
	q = add_queue(q, step);
	bfs(q);
}

void	find_ways(t_node **nodes, int ***ways, int *l)
{
	t_node	*step;
	int		i;
	int		j;

	node_distance(nodes);
	step = get_by_start(*nodes, -1);
	if (!step->way)
		return ;
	*ways = add_route(*ways, step, *l);
	*l = *l + 1;
	i = -1;
	j = 0;
	while (step->way[++i])
		if (step->way[i]->start == 1 || step->way[i]->start == -1)
			j++;
		else if (step->way[i]->start == 0)
			step->way[i]->used = 1;
	if (j == 2 && i == 2)
		return ;
	default_nodes(nodes);
	find_ways(nodes, ways, l);
}

t_way	*create_path(int *way)
{
	t_way	*tmp;
	int		i;

	i = 0;
	tmp = (t_way *)malloc(sizeof(t_way));
	tmp->way = way;
	while (way[i])
		i++;
	tmp->dist = i;
	tmp->next = NULL;
	return (tmp);
}

t_way	*add_path(t_way *path, int *way)
{
	t_way	*tmp;
	int		i;

	i = 0;
	if (!path)
		path = create_path(way);
	else
	{
		tmp = path;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_path(way);
	}
	return (path);
}
