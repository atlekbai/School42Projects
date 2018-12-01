/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 22:07:01 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/04 12:53:31 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*tmp;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	tmp = (char*)malloc((i + 1) * sizeof(*str));
	i = 0;
	if (tmp)
	{
		while (str[i])
		{
			tmp[i] = str[i];
			i++;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	return (0);
}
