/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:43:58 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/11/30 20:54:01 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(char const *src, int c)
{
	char *str;

	str = NULL;
	while (*src != '\0')
	{
		if (*src == (unsigned char)c)
			str = (char*)src;
		src++;
	}
	if ((char)c == '\0')
		return ((char*)src);
	return (str);
}
