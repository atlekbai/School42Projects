/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 10:54:17 by hdanylev          #+#    #+#             */
/*   Updated: 2017/10/31 15:25:58 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*arr;
	unsigned char	tmp;

	arr = (char*)b;
	tmp = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		arr[i] = tmp;
		i++;
	}
	return (arr);
}
