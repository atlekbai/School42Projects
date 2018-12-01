/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 22:43:28 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/20 22:59:15 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (src[i] && len)
	{
		if (!len--)
			return (dst);
		dst[i] = src[i];
		i++;
	}
	while (len--)
	{
		dst[i] = 0;
		i++;
	}
	return (dst);
}
