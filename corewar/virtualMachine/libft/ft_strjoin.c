/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:33:47 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/04 12:56:42 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*substr;
	size_t	len;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	substr = (char*)malloc(len + 1);
	if (substr == NULL)
		return (0);
	i = 0;
	while (s1[i])
	{
		substr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		substr[i++] = s2[j++];
	substr[i] = '\0';
	return (substr);
}
