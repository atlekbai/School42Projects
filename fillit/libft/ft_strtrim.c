/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:42:38 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/23 20:11:15 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_contain_symb(char const *s)
{
	while (*s)
	{
		if (*s != ' ' && *s != '\t' && *s != '\n')
			return (1);
		s++;
	}
	return (0);
}

static int	ft_count_symb(char const *s)
{
	int i;

	i = 0;
	while (*s)
	{
		while (*s == ' ' || *s == '\t' || *s == '\n')
			s++;
		while (is_contain_symb(s) == 1)
		{
			i++;
			s++;
		}
	}
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	res = (char *)malloc(sizeof(char) * (ft_count_symb(s) + 1));
	if (!res)
		return (NULL);
	while (*s)
	{
		while (*s == ' ' || *s == '\t' || *s == '\n')
			s++;
		while (is_contain_symb(s) == 1)
			res[i++] = *s++;
	}
	res[i] = '\0';
	return (res);
}
