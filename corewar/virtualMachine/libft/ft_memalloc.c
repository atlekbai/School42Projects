/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:27:39 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/07 10:55:01 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = (unsigned char*)malloc(size);
	if (tmp == NULL)
		return (0);
	while (i < size)
	{
		tmp[i] = '\0';
		i++;
	}
	return (tmp);
}
