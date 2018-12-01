/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:34:32 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/11/30 18:45:33 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char			*data;
	unsigned int	i;

	i = 0;
	data = (char*)malloc(sizeof(char) * (size + 1));
	if (data)
	{
		while (data[i])
		{
			data[i] = '\0';
			i++;
		}
	}
	return (data);
}
