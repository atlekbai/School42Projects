/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:39:19 by atlekbai          #+#    #+#             */
/*   Updated: 2018/11/04 18:39:19 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		max_3(int a, int b, int c)
{
	if (a > b && a > c)
		return (a);
	else if (b > a && b > c)
		return (b);
	return (c);
}

int		min_3(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	else if (b < a && b < c)
		return (b);
	return (c);
}

void	sort_2_a(t_push_swap *ps)
{
	if (ps->a.list->d > ps->a.list->next->d)
		swap_a(ps);
}

void	sort_2_b(t_push_swap *ps)
{
	if (ps->b.list->d < ps->b.list->next->d)
		swap_b(ps);
}

void	sort_2_ab(t_push_swap *ps)
{
	if (unsorted_stack(ps->a, 2) && sorted_stack(ps->b, 2))
		swap_ab(ps);
	else if (sorted_stack(ps->b, 2))
		sort_2_b(ps);
	else if (unsorted_stack(ps->a, 2))
		sort_2_a(ps);
}
