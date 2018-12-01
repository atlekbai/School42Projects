/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 09:51:27 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/07 16:13:25 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	str = (char*)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while ((size_t)i <= size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
