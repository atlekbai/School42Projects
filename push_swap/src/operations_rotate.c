/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:48:15 by atlekbai          #+#    #+#             */
/*   Updated: 2018/11/01 15:48:15 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rotate_a(t_push_swap *ps)
{
	t_node	*tmp;
	t_node	*head;

	if (ps->a.length <= 1)
		return ;
	head = ps->a.list;
	ps->a.list = head->next;
	tmp = ps->a.list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	head->next = NULL;
	if (ps->print)
		ft_printf("ra\n");
	ps->ops++;
}

void	rotate_b(t_push_swap *ps)
{
	t_node	*tmp;
	t_node	*head;

	if (ps->b.length <= 1)
		return ;
	head = ps->b.list;
	ps->b.list = head->next;
	tmp = ps->b.list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	head->next = NULL;
	if (ps->print)
		ft_printf("rb\n");
	ps->ops++;
}

void	rotate_ab(t_push_swap *ps)
{
	rotate_a(ps);
	rotate_b(ps);
	if (ps->print)
		ft_printf("rr\n");
	ps->ops--;
}
