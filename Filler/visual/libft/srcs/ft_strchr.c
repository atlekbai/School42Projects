/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:44:56 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/01/26 17:58:08 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(char const *src, int c)
{
	while (*src)
	{
		if (*src == (unsigned char)c)
			return ((char*)src);
		src++;
	}
	if ((char)c == '\0')
		return ((char*)src);
	return (NULL);
}
