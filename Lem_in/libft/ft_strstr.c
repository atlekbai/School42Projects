/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:56:34 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/22 20:49:46 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static int	my_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strstr(const char *big, const char *little)
{
	char *s1;
	char *s2;

	s2 = (char *)little;
	if (!(*s2))
		return ((char *)big);
	while (*big)
	{
		if (*big != *little)
		{
			big++;
			continue;
		}
		s1 = (char *)big;
		while (1)
		{
			if (!(*s2))
				return (s1 - my_strlen(little));
			if (*s1++ != *s2++)
				break ;
		}
		s2 = (char *)little;
		big++;
	}
	return (0);
}
