/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:15:08 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/11/30 18:35:50 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(void const *src, int c, size_t n)
{
	unsigned char	*s1;

	s1 = (unsigned char*)src;
	while (n--)
	{
		if (*s1 == (unsigned char)c)
			return (s1);
		s1++;
	}
	return (NULL);
}
