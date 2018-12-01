/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:26:11 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/01/26 19:53:07 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*d;

	i = 0;
	d = NULL;
	if (!s)
		return (0);
	d = (char *)malloc(sizeof(char) * len + 1);
	if (d)
	{
		while (i < len)
		{
			d[i] = s[start];
			i++;
			start++;
		}
		d[i] = '\0';
		return (d);
	}
	else
		return (NULL);
}
