/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:50:07 by dvdovenk          #+#    #+#             */
/*   Updated: 2016/12/12 17:45:43 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_nb_words(char *str, char c)
{
	int	i;
	int	sym;
	int	count;

	i = 0;
	sym = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] != c && str[i])
		{
			i++;
			sym = 1;
		}
		if (str[i] == c || str[i] == '\0')
		{
			if (sym == 1)
				count += 1;
			sym = 0;
			i++;
		}
	}
	return (count);
}

static int	ft_ln_w(char *str, int i, char c)
{
	int	count;

	count = 0;
	while (str[i] != c && str[i])
	{
		count++;
		i++;
	}
	return (count);
}

static char	**ft_fill(char *s, char c, char **res)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			k = 0;
			res[j] = (char*)malloc(sizeof(char) * (ft_ln_w(s, i, c) + 1));
			if (res[j] == NULL)
				return (NULL);
			while (s[i] != c && s[i])
				res[j][k++] = s[i++];
			res[j++][k] = '\0';
		}
	}
	res[j] = NULL;
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	char	*src;

	if (s == NULL)
		return (NULL);
	src = (char*)s;
	res = (char**)malloc(sizeof(char*) * (ft_nb_words(src, c) + 1));
	if (res == NULL)
		return (NULL);
	res = ft_fill(src, c, res);
	return (res);
}
