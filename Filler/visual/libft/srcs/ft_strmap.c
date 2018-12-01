/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 16:35:02 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/12/01 11:56:04 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				res[i] = f(s[i]);
				i++;
			}
			res[i] = '\0';
		}
		return (res);
	}
	return (NULL);
}
