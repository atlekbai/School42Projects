/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:46:23 by atlekbai          #+#    #+#             */
/*   Updated: 2018/04/16 15:46:24 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd(char *s1, char s2)
{
	int		i;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(ft_strlen(s1) + 1 + 1);
	if (!res)
		return (NULL);
	i = ft_strlen(s1);
	res = ft_strcpy(res, s1);
	res[i++] = s2;
	res[i] = '\0';
	ft_strdel(&s1);
	return (res);
}
