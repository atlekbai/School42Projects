/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:57:47 by hdanylev          #+#    #+#             */
/*   Updated: 2017/12/27 17:27:50 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_wcount(const char *str, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			j++;
		i++;
	}
	if (str[0] != c)
		j++;
	if (str[0] == '\0')
		j = 0;
	return (j);
}

static char		*ft_auechka(const char *str, int start, char c)
{
	int		mem;
	int		count;
	char	*tmp;

	mem = 0;
	count = start;
	while (str[count] != c && str[count] != '\0')
	{
		mem++;
		count++;
	}
	tmp = (char*)malloc(sizeof(char) * mem + 1);
	if (tmp == NULL)
		return (0);
	count = 0;
	while (count < mem)
	{
		tmp[count++] = str[start++];
	}
	tmp[count] = '\0';
	return (tmp);
}

char			**ft_strsplit(const char *str, char c)
{
	int		ii;
	int		i;
	int		j;
	char	**mass;

	if (str == NULL)
		return (0);
	j = ft_wcount(str, c);
	mass = (char**)malloc(sizeof(char*) * (j + 1));
	if (mass == NULL)
		return (0);
	i = 0;
	ii = 0;
	while (ii < j)
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		mass[ii] = ft_auechka(str, i, c);
		i = i + ft_strlen(mass[ii]);
		ii++;
	}
	mass[ii] = NULL;
	return (mass);
}
