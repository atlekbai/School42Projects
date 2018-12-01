/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 21:05:33 by hdanylev          #+#    #+#             */
/*   Updated: 2017/10/31 16:48:22 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int						i;
	size_t					t;
	const unsigned char		*str1;
	const unsigned char		*str2;

	t = 0;
	i = 0;
	str1 = s1;
	str2 = s2;
	while (t < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
		t++;
	}
	return (0);
}
