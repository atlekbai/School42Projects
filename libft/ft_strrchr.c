/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:25:12 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/23 22:17:39 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*point;

	point = (char *)s;
	i = 0;
	while (s[i])
		i++;
	while (s[i] != c && s[i] != *point)
		i--;
	if (s[i] == c)
		return ((char*)(s + i));
	return (NULL);
}
