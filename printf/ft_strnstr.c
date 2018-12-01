/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:56:34 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/23 22:43:43 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t p;

	if (*little == '\0')
		return ((char *)big);
	p = ft_strlen(little);
	while (*big && len-- >= p)
	{
		if (ft_strncmp(big, little, p) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
