/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:24:54 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/12/12 18:10:30 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 == '\0' && *s2 == '\0')
			return (0);
		else if (*s1 != *s2)
			return ((*(unsigned char*)s1) - (*(unsigned char*)s2));
		s1++;
		s2++;
		n--;
	}
	return (0);
}
