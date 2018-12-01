/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:17:07 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/22 11:31:45 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (len--)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
