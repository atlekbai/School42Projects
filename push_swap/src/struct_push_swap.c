/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:14:15 by atlekbai          #+#    #+#             */
/*   Updated: 2018/11/01 15:14:16 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_stack(t_stack *stack)
{
	stack->list = NULL;
	stack->length = 0;
}

void	init_push_swap(t_push_swap *ps, int length)
{
	int	i;

	i = -1;
	ps->len = length;
	ps->ops = 0;
	ps->print = 0;
	init_stack(&ps->a);
	init_stack(&ps->b);
	while (++i < length)
		push_back(&ps->a, ps->array[i]);
}

void	print_push_swap(t_push_swap ps)
{
	ft_printf("Stack A: ");
	while (ps.a.list)
	{
		ft_printf("%d ", ps.a.list->d);
		ps.a.list = ps.a.list->next;
	}
	ft_printf("\nStack B: ");
	while (ps.b.list)
	{
		ft_printf("%d ", ps.b.list->d);
		ps.b.list = ps.b.list->next;
	}
	ft_printf("\n");
	ft_printf("ops: %d\n", ps.ops);
}
