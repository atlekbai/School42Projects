/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:21:56 by atlekbai          #+#    #+#             */
/*   Updated: 2018/11/01 15:21:56 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	push_a(t_push_swap *ps)
{
	if (ps->print)
		ft_printf("pa\n");
	if (ps->b.length > 0)
		push_front(&ps->a, pop(&ps->b));
	ps->ops++;
}

void	push_b(t_push_swap *ps)
{
	if (ps->print)
		ft_printf("pb\n");
	if (ps->a.length > 0)
		push_front(&ps->b, pop(&ps->a));
	ps->ops++;
}
