/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 12:18:22 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/05 12:18:23 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node		*get_by_start(t_node *node, int start)
{
	t_node *step;

	step = node;
	while (step)
	{
		if (step->start == start)
			return (step);
		step = step->next;
	}
	return (0);
}

t_node		*get_by_id(t_node *node, int id)
{
	while (node)
	{
		if (node->id == id || node->id == 0)
			return (node);
		node = node->next;
	}
	return (0);
}

t_node		*get_node_by_name(t_node **nodes, char *name)
{
	t_node *temp;

	temp = *nodes;
	while (temp)
	{
		if (ft_strequ(name, temp->name))
			return (temp);
		temp = temp->next;
	}
	return (0);
}
