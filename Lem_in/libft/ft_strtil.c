/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 17:11:11 by atlekbai          #+#    #+#             */
/*   Updated: 2018/04/30 17:12:19 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtil(char *str, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	new = ft_strnew(i);
	i = 0;
	while (*str)
	{
		if (*str == c)
			break ;
		new[i++] = *str++;
	}
	return (new);
}
