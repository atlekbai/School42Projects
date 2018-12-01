/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 22:03:05 by atlekbai          #+#    #+#             */
/*   Updated: 2018/04/12 22:03:05 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_end(char c)
{
	char const *convs = "diDuUoOxXcCsSp%%";

	while (*convs)
		if (*convs++ == c)
			return (1);
	return (0);
}

int		is_spec(char c)
{
	char const	*signs = "# 0-+.123456789jzhl";

	while (*signs)
		if (*signs++ == c)
			return (1);
	return (0);
}

int		ft_isnotzero(int c)
{
	if (c >= '1' && c <= '9')
		return (1);
	return (0);
}

char	*ft_dgtchr(const char *s)
{
	while (*s && (*s == '#' || *s == ' ' || *s == '-' || *s == '+' ||
			(ft_isdigit(*s) && ft_isnotzero(*s) == 0)))
		s++;
	if (*s)
		return ((char *)s);
	return (NULL);
}

char	*ft_mod(char *s)
{
	int i;
	int len;

	i = ft_strlen(s) - 1;
	if (s[i] == '%')
		return (0);
	if (i < 0)
		return (0);
	len = i;
	while (i >= 0 && ft_isalpha(s[i]))
		i--;
	if (i == len - 1)
		return (0);
	if ((len - i - 1) < 0)
		return (0);
	return (ft_strsub(s, i + 1, len - i - 1));
}
