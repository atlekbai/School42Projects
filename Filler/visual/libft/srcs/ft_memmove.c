/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:10:46 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/11/30 18:36:17 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	unsigned char	*buf;
	size_t			i;

	i = 0;
	buf = (unsigned char *)malloc(len);
	if (buf)
	{
		while (i < len)
		{
			buf[i] = ((unsigned char *)src)[i];
			i++;
		}
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = buf[i];
			i++;
		}
	}
	free(buf);
	return (dst);
}
