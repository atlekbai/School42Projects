/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:43:16 by atlekbai          #+#    #+#             */
/*   Updated: 2018/10/31 13:43:16 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push_front(t_stack *stack, int data)
{
	t_node	*new;

	new = create_elem(data);
	new->next = stack->list;
	stack->list = new;
	stack->length++;
}

void	push_back(t_stack *stack, int data)
{
	t_node	*tmp;
	t_node	*new;

	new = create_elem(data);
	stack->length++;
	if (stack->list == NULL)
	{
		stack->list = new;
		return ;
	}
	tmp = stack->list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

int		pop(t_stack *stack)
{
	t_node	*tmp;
	int		data;

	if (stack->length == 0)
		return (0);
	data = stack->list->d;
	tmp = stack->list;
	stack->list = stack->list->next;
	free(tmp);
	stack->length--;
	return (data);
}

int		sorted_stack(t_stack stack, int n)
{
	int		i;
	t_node	*tmp;

	if (stack.list == NULL)
		return (0);
	i = 0;
	tmp = stack.list;
	while (tmp->next && i < n - 1)
	{
		if (tmp->d > tmp->next->d)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int		unsorted_stack(t_stack stack, int n)
{
	int		i;
	t_node	*tmp;

	if (stack.list == NULL)
		return (0);
	i = 0;
	tmp = stack.list;
	while (tmp->next && i < n - 1)
	{
		if (tmp->d < tmp->next->d)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}
