/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:49:32 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/24 13:06:32 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int i;
	int count;

	i = 1;
	count = 0;
	if (*s == '\0')
		return (0);
	if (s[0] != c)
		count++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static int	ft_len_word(char const *s, char c)
{
	int len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		res[i] = (char *)malloc(ft_len_word(s, c) + 1);
		j = 0;
		while (*s != c && *s)
			res[i][j++] = *s++;
		res[i++][j] = '\0';
	}
	res[i] = 0;
	return (res);
}
