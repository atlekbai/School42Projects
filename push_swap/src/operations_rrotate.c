/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:00:20 by atlekbai          #+#    #+#             */
/*   Updated: 2018/11/01 16:00:21 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rev_rotate_a(t_push_swap *ps)
{
	t_node	*tmp;

	if (ps->a.length < 2)
		return ;
	tmp = ps->a.list;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = ps->a.list;
	ps->a.list = tmp->next;
	tmp->next = NULL;
	if (ps->print)
		ft_printf("rra\n");
	ps->ops++;
}

void	rev_rotate_b(t_push_swap *ps)
{
	t_node	*tmp;

	if (ps->b.length < 2)
		return ;
	tmp = ps->b.list;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = ps->b.list;
	ps->b.list = tmp->next;
	tmp->next = NULL;
	if (ps->print)
		ft_printf("rrb\n");
	ps->ops++;
}

void	rev_rotate_ab(t_push_swap *ps)
{
	rev_rotate_a(ps);
	rev_rotate_b(ps);
	if (ps->print)
		ft_printf("rrr\n");
	ps->ops--;
}
