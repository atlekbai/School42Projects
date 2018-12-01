/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 20:34:11 by hdanylev          #+#    #+#             */
/*   Updated: 2017/10/31 11:09:32 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	i;
	size_t			t;
	unsigned char	*data;

	i = (unsigned char)c;
	t = 0;
	data = (unsigned char*)src;
	while (t < n)
	{
		if (data[t] == i)
		{
			return (&data[t]);
		}
		t++;
	}
	return (0);
}
