/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:40:23 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/11/30 18:36:24 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *str, int ch, size_t len)
{
	unsigned char	*ptr;

	ptr = str;
	while (len)
	{
		*ptr = (unsigned char)ch;
		ptr++;
		len--;
	}
	return (str);
}
