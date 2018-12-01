/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:10:08 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/12/01 11:58:20 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if ((!s1 && s2) || (!s2 && s1) || (!s2 && !s1))
		return (0);
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		else
			i++;
	}
	return (1);
}
