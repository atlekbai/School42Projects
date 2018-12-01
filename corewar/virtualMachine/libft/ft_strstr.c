/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:58:58 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/07 16:08:11 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_cmpn(const char *tmp, const char *srch, int i)
{
	int	j;

	j = 0;
	while (srch[j])
	{
		if (tmp[i] != srch[j])
		{
			return (tmp[i] - srch[j]);
		}
		j++;
		i++;
	}
	return (0);
}

char		*ft_strstr(const char *tmp, const char *srch)
{
	int j;
	int	i;

	i = 0;
	if (srch[0] == '\0')
		return ((char*)tmp);
	while (tmp[i] != '\0')
	{
		if (tmp[i] == srch[0])
		{
			if ((j = ft_cmpn(tmp, srch, i)) == 0)
			{
				return ((char*)&tmp[i]);
			}
		}
		i++;
	}
	return (0);
}
