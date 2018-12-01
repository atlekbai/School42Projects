/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:50:12 by hdanylev          #+#    #+#             */
/*   Updated: 2017/10/31 16:56:28 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		t;
	char		*arr;
	const char	*data;

	t = 0;
	arr = (char*)dst;
	data = (const char*)src;
	while (t < n)
	{
		arr[t] = data[t];
		t++;
	}
	return (arr);
}
