/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:13:02 by atlekbai          #+#    #+#             */
/*   Updated: 2018/11/01 15:13:02 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	swap_a_(t_push_swap *ps)
{
	t_node *first;
	t_node *second;

	if (ps->a.length <= 1)
		return (0);
	first = ps->a.list;
	second = first->next;
	first->next = second->next;
	second->next = first;
	ps->a.list = second;
	return (1);
}

static int	swap_b_(t_push_swap *ps)
{
	t_node *first;
	t_node *second;

	if (ps->b.length <= 1)
		return (0);
	first = ps->b.list;
	second = first->next;
	first->next = second->next;
	second->next = first;
	ps->b.list = second;
	return (1);
}

void		swap_a(t_push_swap *ps)
{
	if (swap_a_(ps) == 0)
		return ;
	if (ps->print)
		ft_printf("sa\n");
	ps->ops++;
}

void		swap_b(t_push_swap *ps)
{
	if (swap_b_(ps) == 0)
		return ;
	if (ps->print)
		ft_printf("sb\n");
	ps->ops++;
}

void		swap_ab(t_push_swap *ps)
{
	swap_a_(ps);
	swap_b_(ps);
	if (ps->print)
		ft_printf("ss\n");
	ps->ops++;
}
