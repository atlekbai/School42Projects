/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:10:41 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/11/30 18:44:26 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *dest, char const *src, size_t len)
{
	int		i;

	i = 0;
	while (src[i] != '\0' && i < (int)len)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < (int)len)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
