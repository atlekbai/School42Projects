/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 12:16:40 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/05 12:16:41 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_queue	*add_queue(t_queue *q, t_node *node)
{
	t_queue *temp;
	t_queue *new;
	t_queue *loop;

	loop = q;
	while (loop)
	{
		if (loop->node->id == node->id)
			return (q);
		loop = loop->next;
	}
	new = (t_queue *)malloc(sizeof(t_queue));
	new->node = node;
	new->next = NULL;
	if (!q)
		q = new;
	else
	{
		temp = q;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	return (q);
}

t_node	*pop_queue(t_queue **queue)
{
	t_queue *temp;
	t_node	*node;

	temp = *queue;
	node = temp->node;
	*queue = (*queue)->next;
	free(temp);
	temp = NULL;
	return (node);
}
