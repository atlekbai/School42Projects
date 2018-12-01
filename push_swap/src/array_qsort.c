/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_qsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 22:48:51 by atlekbai          #+#    #+#             */
/*   Updated: 2018/11/01 22:48:57 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *a, int low, int high)
{
	int pivot;
	int j;
	int i;

	pivot = a[low];
	j = low;
	i = low;
	while (++i <= high)
		if (a[i] <= pivot)
			ft_swap(&a[i], &a[++j]);
	ft_swap(&a[low], &a[j]);
	return (j);
}

void		q_sort(int *a, int low, int high)
{
	int	mid;

	if (low >= high)
		return ;
	mid = partition(a, low, high);
	q_sort(a, low, mid - 1);
	q_sort(a, mid + 1, high);
}

int			ft_median(t_stack stack, int n)
{
	int	arr[100000];
	int	i;

	i = 0;
	while (stack.list && i < n)
	{
		arr[i++] = stack.list->d;
		stack.list = stack.list->next;
	}
	q_sort(arr, 0, i - 1);
	return (arr[(i - 1) / 2]);
}
