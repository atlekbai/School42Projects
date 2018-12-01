/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:29:13 by atlekbai          #+#    #+#             */
/*   Updated: 2018/10/31 13:38:08 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		sort_second(t_push_swap *ps, int n)
{
	int i;
	int	pushed;
	int	top_half;
	int	med;

	(n == 2) ? sort_2_b(ps) : NULL;
	(n == 3) ? sort_3_b(ps) : NULL;
	if (n < 4 || unsorted_stack(ps->b, n) == 1)
		return (0);
	top_half = 0;
	med = ft_median(ps->b, n);
	i = -1;
	while (++i < n)
		(ps->b.list->d > med && (top_half++) >= 0) ? push_a(ps) : rotate_b(ps);
	i = -1;
	while (ps->b.length != n - top_half && ++i < n - top_half)
		rev_rotate_b(ps);
	pushed = top_half + sort_second(ps, n - top_half);
	if (!true_sorted(*ps) && (i = -1))
	{
		while (++i < top_half)
			push_b(ps);
		pushed -= top_half;
	}
	return (pushed + sort_second(ps, top_half));
}

int		get_best_move(t_stack stack, int median)
{
	int		i;
	int		best;
	t_node	*tmp;
	int		mid;

	i = 0;
	best = -1;
	mid = stack.length / 2;
	tmp = stack.list;
	while (tmp)
	{
		if (tmp->d < median && (ABS(mid - i) > ABS(mid - best) || best == -1))
			best = i;
		i++;
		tmp = tmp->next;
	}
	return (best > mid) ? 0 : 1;
}

void	insert_sort(t_push_swap *ps, int n)
{
	int	i;
	int cmd;
	int start;

	(n == 2) ? sort_2_b(ps) : NULL;
	(n == 3) ? sort_3_b(ps) : NULL;
	if (n < 4 && unsorted_stack(ps->b, n) == 1)
	{
		i = -1;
		while (++i < n)
			push_a(ps);
		return ;
	}
	i = -1;
	start = 0;
	while (++i < n)
	{
		while (ps->b.list->d != max_stack(ps->b, start, n))
		{
			((cmd = get_big(ps->b)) == 0) ? rotate_b(ps) : rev_rotate_b(ps);
			start += (cmd == 0) ? -1 : 1;
		}
		push_a(ps);
	}
}

void	sort(t_push_swap *ps, int n)
{
	int	top_half;
	int	med;

	(n == 2) ? sort_2_a(ps) : NULL;
	(n == 3) ? sort_3_a(ps) : NULL;
	if (n < 4 || sorted_stack(ps->a, n) == 1)
		return ;
	top_half = 0;
	med = ft_median(ps->a, n);
	while (smaller_in(ps->a, ps->a.length, med))
		if (ps->a.list->d < med)
		{
			push_b(ps);
			top_half++;
		}
		else
			(get_best_move(ps->a, med) == 1) ? rotate_a(ps) : rev_rotate_a(ps);
	sort(ps, n - top_half);
	(ps->len < 150) ? insert_sort(ps, top_half) : NULL;
	if (ps->len < 150)
		return ;
	top_half -= sort_second(ps, top_half);
	while (top_half--)
		push_a(ps);
}

/*
**	main
*/

int		main(int ac, char **av)
{
	char		**numbers;
	int			i;
	t_push_swap	push_swap;

	if (ac != 2)
	{
		ft_printf("Usage: %s [args]\n", av[0]);
		ft_printf("\t args - numbers\n");
		return (0);
	}
	i = -1;
	numbers = ft_strsplit(av[1], 32);
	while (numbers[++i])
	{
		if (check_num(numbers[i]) == 0)
			ft_exit();
		push_swap.array[i] = ft_atoi(numbers[i]);
	}
	init_push_swap(&push_swap, i);
	push_swap.print = 1;
	q_sort(push_swap.array, 0, i - 1);
	if (check_array(push_swap.array, i) == 0)
		ft_exit();
	sort(&push_swap, i);
	return (0);
}
