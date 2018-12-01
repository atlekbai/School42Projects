/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:23:04 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/11/30 18:37:49 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(char const *src)
{
	char	*s;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (src[i] != '\0')
		i++;
	s = (char *)malloc(sizeof(char) * i + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		s[k] = src[i];
		k++;
		i++;
	}
	s[k] = '\0';
	return (s);
}
