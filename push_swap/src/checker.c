/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:58:07 by atlekbai          #+#    #+#             */
/*   Updated: 2018/11/05 20:58:07 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	process(const char *line, t_push_swap *ps)
{
	if (ft_strequ(line, "sa"))
		swap_a(ps);
	else if (ft_strequ(line, "sb"))
		swap_b(ps);
	else if (ft_strequ(line, "ss"))
		swap_ab(ps);
	else if (ft_strequ(line, "pa"))
		push_a(ps);
	else if (ft_strequ(line, "pb"))
		push_b(ps);
	else if (ft_strequ(line, "ra"))
		rotate_a(ps);
	else if (ft_strequ(line, "rb"))
		rotate_b(ps);
	else if (ft_strequ(line, "rr"))
		rotate_ab(ps);
	else if (ft_strequ(line, "rra"))
		rev_rotate_a(ps);
	else if (ft_strequ(line, "rrb"))
		rev_rotate_b(ps);
	else if (ft_strequ(line, "rrr"))
		rev_rotate_ab(ps);
	else
		ft_exit();
}

int		main(int ac, char **av)
{
	int			i;
	t_push_swap	ps;
	char		*line;
	char		**numbers;

	if (ac != 2)
		return (0);
	numbers = ft_strsplit(av[1], 32);
	i = -1;
	while (numbers[++i])
	{
		(check_num(numbers[i]) == 0) ? ft_exit() : NULL;
		ps.array[i] = ft_atoi(numbers[i]);
	}
	init_push_swap(&ps, i);
	q_sort(ps.array, 0, i - 1);
	(check_array(ps.array, i) == 0) ? ft_exit() : NULL;
	while (get_next_line(0, &line) > 0)
	{
		process(line, &ps);
		free(line);
	}
	ft_printf("%s\n", (sorted_stack(ps.a, i) == 1
						&& ps.b.length == 0) ? "OK" : "KO");
	return (0);
}
