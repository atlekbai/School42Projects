/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:07:34 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/25 00:00:30 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (destination);
	while (n--)
	{
		((char*)destination)[i] = ((char*)source)[i];
		i++;
	}
	return (destination);
}
