/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strsplit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:13:45 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/25 17:25:38 by atlekbai         ###   ########.fr       */
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

t_list		*ft_lst_strsplit(char const *s, char c)
{
	t_list	*res;
	char	*temp;
	int		j;
	t_list	*list;

	if (!s)
		return (NULL);
	res = ft_lstnew(NULL, 0);
	if (!res)
		return (0);
	while (ft_count_words(s, c) > 0)
	{
		while (*s == c)
			s++;
		temp = (char *)malloc(ft_len_word(s, c) + 1);
		j = 0;
		while (*s != c && *s)
			temp[j++] = *s++;
		temp[j] = '\0';
		list = ft_lstnew(temp, j);
		ft_lstadd(&res, list);
	}
	return (res);
}
