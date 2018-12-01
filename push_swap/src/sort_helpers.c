/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:37:10 by atlekbai          #+#    #+#             */
/*   Updated: 2018/11/08 15:37:10 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		place_in(t_stack stack, int n)
{
	t_node *tmp;

	tmp = stack.list;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->d < stack.list->d && tmp->d > n)
		return (0);
	if (stack.list->d > n)
		return (1);
	return (0);
}

int		get_place(t_stack stack, int n)
{
	int		best_i;
	int		prev;
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack.list;
	while (tmp->next)
		tmp = tmp->next;
	prev = tmp->d;
	tmp = stack.list;
	if (prev < tmp->d && prev > n)
		return (1);
	while (tmp)
	{
		if ((prev < n || prev == -1) && tmp->d > n)
			best_i = i;
		prev = tmp->d;
		tmp = tmp->next;
		i++;
	}
	return ((best_i < stack.length / 2) ? 0 : 1);
}

int		min_stack(t_stack stack)
{
	int		min;
	t_node	*tmp;

	tmp = stack.list;
	min = tmp->d;
	while (tmp)
	{
		if (tmp->d < min)
			min = tmp->d;
		tmp = tmp->next;
	}
	return (min);
}

int		max_stack(t_stack stack, int start, int len)
{
	int		i;
	int		max;
	t_node	*tmp;

	i = -1;
	tmp = stack.list;
	if (start < 0)
		while (tmp && ++i < stack.length + start)
			tmp = tmp->next;
	max = tmp->d;
	i = -1;
	while (tmp && ++i < len)
	{
		if (tmp->d > max)
			max = tmp->d;
		if (tmp->next == NULL)
			tmp = stack.list;
		else
			tmp = tmp->next;
	}
	return (max);
}

int		get_big(t_stack stack)
{
	int		max;
	int		max_i;
	int		i;
	t_node	*tmp;

	tmp = stack.list;
	max_i = 0;
	i = 0;
	max = tmp->d;
	while (tmp)
	{
		if (tmp->d > max)
		{
			max = tmp->d;
			max_i = i;
		}
		i++;
		tmp = tmp->next;
	}
	return ((max_i < stack.length / 2) ? 0 : 1);
}
