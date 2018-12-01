/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:18:16 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/12/12 17:03:58 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t s;
	size_t m;

	s = 0;
	m = 0;
	while (dest[m])
		m++;
	while (src[s] && (m + 1) < size)
		dest[m++] = src[s++];
	dest[m] = '\0';
	if (!s)
		m = size;
	while (src[s++])
		m++;
	return (m);
}
