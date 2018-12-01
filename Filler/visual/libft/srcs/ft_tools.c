/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 21:44:37 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/02/07 21:44:38 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_place_shift_fd(int size, int fd)
{
	int	j;

	j = 0;
	while (j < size)
	{
		ft_putchar_fd(' ', fd);
		j++;
	}
}

char	*ft_place_zero(int size)
{
	int		j;
	char	*data;

	j = 0;
	data = ft_strnew(size);
	while (j < size)
	{
		data[j] = '0';
		j++;
	}
	data[j] = '\0';
	return (data);
}

int		ft_output_len(const char *str, int pos)
{
	int	num;

	num = 0;
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		num *= 10;
		num += str[pos] - '0';
		pos++;
	}
	return (num);
}

char	*ft_takestring(const char *s, int p, t_desc *list)
{
	int		j;
	char	*data;

	j = 0;
	while (s[p] && (s[p] == 'z' || s[p] == 'j' || s[p] == 'l' || s[p] == 'h' ||
		s[p] == '-' || s[p] == '+' || s[p] == ' ' || s[p] == '#' ||
		(s[p] >= '0' && s[p] <= '9') || s[p] == '.' || s[p] == '*' ||
		s[p] == '$' || s[p] == 'L' || s[p] == 39))
	{
		j++;
		p++;
	}
	data = ft_strsub(s, p - j, j);
	list->spec = s[p];
	return (data);
}

int		ft_last_flag(char *s)
{
	int	j;
	int	p;

	j = 0;
	p = 0;
	while (s[j])
	{
		if ((s[j] == '+' || s[j] == '-' || s[j] == ' ' ||
			s[j] == '0' || s[j] == '#' || s[j] == '*') &&
			(s[j + 1] >= '1' && s[j + 1] <= '9'))
			p = j;
		j++;
	}
	return (p);
}
