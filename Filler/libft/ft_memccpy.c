/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:07:34 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/23 22:23:52 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char*)destination)[i] = ((char*)source)[i];
		if (((char*)source)[i] == (char)c)
			return ((unsigned char *)destination + i + 1);
		i++;
	}
	return (NULL);
}
