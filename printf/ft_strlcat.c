/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 23:11:35 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/24 16:19:15 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s1;
	char	*s2;
	size_t	p;

	s1 = (char *)ft_memchr(dst, '\0', size);
	if (!s1)
		return (size + ft_strlen(src));
	s2 = (char *)src;
	p = (size_t)(s1 - dst) + ft_strlen(s2);
	while ((size_t)(s1 - dst) < size - 1 && *s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (p);
}
