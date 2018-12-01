/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:43:27 by atlekbai          #+#    #+#             */
/*   Updated: 2018/10/31 13:43:27 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "printf.h"
# define ABS(x) ((x < 0) ? -(x) : x)

/*
** node (list)
*/
typedef struct	s_node
{
	int				d;
	struct s_node	*next;
}				t_node;
t_node			*create_elem(int d);
/*
** stack
*/
typedef struct	s_stack
{
	t_node	*list;
	int		length;
}				t_stack;
void			push_front(t_stack *stack, int data);
void			push_back(t_stack *stack, int data);
int				pop(t_stack *stack);
/*
** push_swap struct
*/
typedef struct	s_push_swap
{
	t_stack	a;
	t_stack	b;
	int		array[100000];
	int		len;
	int		ops;
	int		print;
}				t_push_swap;
void			init_stack(t_stack *stack);
void			init_push_swap(t_push_swap *ps, int length);
void			print_push_swap(t_push_swap ps);
/*
** operations
*/
void			swap_a(t_push_swap *ps);
void			swap_b(t_push_swap *ps);
void			swap_ab(t_push_swap *ps);
void			push_a(t_push_swap *ps);
void			push_b(t_push_swap *ps);
void			rotate_a(t_push_swap *ps);
void			rotate_b(t_push_swap *ps);
void			rotate_ab(t_push_swap *ps);
void			rev_rotate_a(t_push_swap *ps);
void			rev_rotate_b(t_push_swap *ps);
void			rev_rotate_ab(t_push_swap *ps);
/*
** validation
*/
int				check_num(char *str);
int				check_array(int *arr, int len);
void			ft_exit(void);
/*
** other
*/
void			q_sort(int *a, int low, int high);
int				sorted_stack(t_stack stack, int n);
int				unsorted_stack(t_stack stack, int n);
int				max_3(int a, int b, int c);
int				min_3(int a, int b, int c);
void			sort(t_push_swap *ps, int n);
void			sort_2_a(t_push_swap *ps);
void			sort_2_b(t_push_swap *ps);
void			sort_2_ab(t_push_swap *ps);
int				ft_median(t_stack stack, int n);
int				place_in(t_stack stack, int n);
int				get_place(t_stack stack, int n);
int				min_stack(t_stack stack);
int				max_stack(t_stack stack, int start, int len);
int				get_big(t_stack stack);
void			sort_3_a(t_push_swap *ps);
void			sort_3_b_helper(t_push_swap *ps);
void			sort_3_b(t_push_swap *ps);
int				true_sorted(t_push_swap ps);
int				smaller_in(t_stack stack, int n, int median);

#endif
