/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:30:25 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/12/12 18:10:35 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(char const *big, char const *lit, size_t len)
{
	size_t	a;
	size_t	i;

	a = 0;
	i = 0;
	if (!*lit)
		return ((char*)big);
	while (big[a] != '\0')
	{
		i = 0;
		if (len == 0)
			return (NULL);
		while ((lit[i] == big[a + i]) && (len - 1) >= i)
		{
			if (lit[i + 1] == '\0')
				return ((char*)&big[a]);
			i++;
		}
		len--;
		a++;
	}
	return (NULL);
}
