/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:33:41 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/12/01 12:14:28 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		k;
	int		i;
	size_t	res;
	char	*d;

	k = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	res = ft_strlen(s1) + ft_strlen(s2);
	d = (char *)malloc(sizeof(char) * (res + 1));
	if (d)
	{
		while (s1[i] != '\0')
			d[k++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			d[k++] = s2[i++];
		d[k] = '\0';
		return (d);
	}
	else
		return (NULL);
}
