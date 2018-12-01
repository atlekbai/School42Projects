/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:39:00 by atlekbai          #+#    #+#             */
/*   Updated: 2018/11/08 15:39:00 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_3_a(t_push_swap *ps)
{
	int	a;
	int	b;
	int	c;

	if (sorted_stack(ps->a, 3))
		return ;
	a = ps->a.list->d;
	b = ps->a.list->next->d;
	c = ps->a.list->next->next->d;
	(max_3(a, b, c) == c) ? swap_a(ps) : NULL;
	if (max_3(a, b, c) == c)
		return ;
	if (ps->a.length == 3)
	{
		(max_3(a, b, c) == a) ? rotate_a(ps) : rev_rotate_a(ps);
		(max_3(a, b, c) == a && b > c) ? swap_a(ps) : NULL;
		(max_3(a, b, c) == b && c > a) ? swap_a(ps) : NULL;
		return ;
	}
	(max_3(a, b, c) == a) ? swap_a(ps) : NULL;
	rotate_a(ps);
	swap_a(ps);
	rev_rotate_a(ps);
	(max_3(a, b, c) == a && b > c) ? swap_a(ps) : NULL;
	(max_3(a, b, c) == b && a > c) ? swap_a(ps) : NULL;
}

void	sort_3_b_helper(t_push_swap *ps)
{
	rotate_b(ps);
	swap_b(ps);
	rev_rotate_b(ps);
}

void	sort_3_b(t_push_swap *ps)
{
	int	a;
	int	b;
	int	c;

	if (unsorted_stack(ps->b, 3))
		return ;
	a = ps->b.list->d;
	b = ps->b.list->next->d;
	c = ps->b.list->next->next->d;
	if (ps->b.length == 3)
	{
		(min_3(a, b, c) == c) ? swap_b(ps) : NULL;
		if (min_3(a, b, c) == c)
			return ;
		(min_3(a, b, c) == a) ? rotate_b(ps) : rev_rotate_b(ps);
		(min_3(a, b, c) == a && c > b) ? swap_b(ps) : NULL;
		(min_3(a, b, c) == b && a > c) ? swap_b(ps) : NULL;
		return ;
	}
	(max_3(a, b, c) == b) ? swap_b(ps) : NULL;
	if (max_3(a, b, c) == b && a > c)
		return ;
	sort_3_b_helper(ps);
	(max_3(a, b, c) == c) ? swap_b(ps) : NULL;
	(max_3(a, b, c) == c && a < b) ? sort_3_b_helper(ps) : NULL;
}

int		true_sorted(t_push_swap ps)
{
	t_node	*tmp;
	int		i;

	i = 0;
	while (ps.array[i] != ps.a.list->d)
		i++;
	tmp = ps.a.list;
	while (tmp)
	{
		if (tmp->d != ps.array[i])
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

int		smaller_in(t_stack stack, int n, int median)
{
	t_node	*tmp;
	int		i;

	i = -1;
	tmp = stack.list;
	while (tmp && ++i < n)
	{
		if (tmp->d < median)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
