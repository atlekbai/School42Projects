/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 20:45:44 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/04 20:45:45 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_ant	*ants_add(t_ant *ants, int id, t_node *node)
{
	t_ant *tmp;
	t_ant *wooh;

	if (!ants)
	{
		ants = (t_ant *)malloc(sizeof(t_ant));
		ants->id = id;
		ants->cur = node;
		ants->way = 0;
		ants->next = NULL;
	}
	else
	{
		tmp = ants;
		while (tmp->next)
			tmp = tmp->next;
		wooh = (t_ant *)malloc(sizeof(t_ant));
		wooh->id = id;
		wooh->end = 0;
		wooh->cur = node;
		wooh->way = 0;
		wooh->next = NULL;
		tmp->next = wooh;
	}
	return (ants);
}

int		is_ants_at_end(t_ant *ants)
{
	while (ants)
	{
		if (ants->cur->start != -1)
			return (0);
		ants = ants->next;
	}
	return (1);
}

int		get_index_in_arr(t_node *node, int *way)
{
	int i;

	i = 0;
	while (way[i])
	{
		if (way[i] == node->id)
			break ;
		i++;
	}
	return (i);
}

int		get_next_way(t_node **node, int *way, t_node *nodes)
{
	t_node	*temp;
	int		i;

	i = get_index_in_arr(*node, way);
	if ((*node)->start == -1)
	{
		(*node)->visited = 0;
		return (1);
	}
	temp = get_by_id(nodes, way[i + 1]);
	if (temp->visited == 1)
		return (0);
	(*node)->visited = 0;
	if (temp->start != -1)
		temp->visited = 1;
	*node = temp;
	return (1);
}
