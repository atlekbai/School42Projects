/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:05:26 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/11/30 18:36:05 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned char		*s1;
	const unsigned char	*s2;

	s1 = dst;
	s2 = src;
	while (n--)
		*s1++ = *s2++;
	return (dst);
}
