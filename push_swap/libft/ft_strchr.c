/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:14:10 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/04 12:52:56 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	ch;

	ch = (char)c;
	i = 0;
	while (str[i])
	{
		if (str[i + 1] == '\0')
		{
			if (ch == '\0')
				return ((char*)&str[i + 1]);
		}
		if (str[i] == ch)
		{
			return ((char*)&str[i]);
		}
		i++;
	}
	return (0);
}
