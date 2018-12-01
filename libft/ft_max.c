/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:10:39 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/25 16:12:47 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int *tab, int size)
{
	int	max;
	int	i;

	i = 0;
	max = tab[0];
	while (++i < size)
		if (tab[i] > max)
			max = tab[i];
	return (max);
}