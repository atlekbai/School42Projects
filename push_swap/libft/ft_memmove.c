/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:26:29 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/06 14:45:39 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int			zero;
	size_t		t;
	char		*arr;
	const char	*data;

	zero = n - 1;
	t = 0;
	arr = (char*)dst;
	data = (const char*)src;
	if (dst > src)
	{
		while (zero >= 0)
		{
			arr[zero] = data[zero];
			zero--;
		}
		return (arr);
	}
	while (t < n)
	{
		arr[t] = data[t];
		t++;
	}
	return (arr);
}
