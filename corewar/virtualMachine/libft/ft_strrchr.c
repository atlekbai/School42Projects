/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:51:20 by hdanylev          #+#    #+#             */
/*   Updated: 2017/10/31 12:16:41 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	ch;

	ch = c;
	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == ch)
		{
			return ((char*)&str[i]);
		}
		i--;
	}
	return (0);
}
