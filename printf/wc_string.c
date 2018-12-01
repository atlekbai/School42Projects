/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:15:08 by atlekbai          #+#    #+#             */
/*   Updated: 2018/04/16 16:15:08 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	wc_putstr(wchar_t *s)
{
	if (s != NULL)
		while (*s)
			ft_putchar(*s++);
}

wchar_t	*wc_strsub(wchar_t *s, unsigned int start, int len)
{
	wchar_t	*res;
	int		i;

	if (!s)
		return (NULL);
	res = (wchar_t *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (len >= get_bytes(s[start]))
	{
		len -= get_bytes(s[start]);
		res[i++] = s[start++];
	}
	res[i] = '\0';
	return (res);
}

size_t	wc_strlen(wchar_t *s)
{
	size_t i;
	size_t res;

	i = 0;
	res = 0;
	while (s[i])
	{
		res += get_bytes(s[i]);
		i++;
	}
	return (res);
}

int		big_s_check(wchar_t *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (get_bytes(str[i]) > MB_CUR_MAX)
			return (0);
		i++;
	}
	return (1);
}
