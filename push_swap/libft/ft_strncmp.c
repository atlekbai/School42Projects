/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:07:28 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/07 12:51:54 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_strncmp(char *s1, char *s2, size_t len)
{
	size_t	col;
	int		i;

	if (len == 0)
		return (0);
	col = 0;
	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0' && s2[i] != '\0'))
	{
		if (col == len - 1)
			return (s1[i] - s2[i]);
		col++;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
