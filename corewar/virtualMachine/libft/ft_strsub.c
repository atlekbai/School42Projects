/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 12:48:12 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/07 16:02:32 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	col;

	if (s == NULL)
		return (0);
	col = (size_t)start;
	col = 0;
	substr = (char*)malloc(len + 1);
	if (substr == NULL)
		return (0);
	while (s[start] != '\0' && col < len)
	{
		substr[col] = s[start];
		start++;
		col++;
	}
	substr[col] = '\0';
	return (substr);
}
