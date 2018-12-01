/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:02:45 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/12/01 11:57:12 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	i = 0;
	if (s)
	{
		res = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (res)
		{
			while (s[i])
			{
				res[i] = f(i, s[i]);
				i++;
			}
			res[i] = '\0';
		}
		return (res);
	}
	return (NULL);
}
