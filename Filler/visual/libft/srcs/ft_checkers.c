/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 21:40:59 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/02/07 21:41:00 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_check_how_many(char *str, int pos, char c)
{
	int		count;

	count = 0;
	while (str[pos])
	{
		if (str[pos] == c)
			count++;
		pos++;
	}
	return (count % 2);
}

void		ft_check_flag(char *str, t_desc *list)
{
	int		j;

	j = 0;
	while (str[j])
	{
		if (str[j] == '+')
			list->flag_plus = 1;
		if (str[j] == '-')
			list->flag_min = 1;
		if (str[j] == ' ')
			list->flag_space = 1;
		if (str[j] == '0' && (str[j - 1] < 48 || str[j - 1] > 57) &&
			str[j - 1] != '.')
			list->flag_zero = 1;
		if (str[j] == '#')
			list->flag_hash = 1;
		j++;
	}
}

void		ft_check_prec(char *str, t_desc *list)
{
	int		j;
	int		p;

	j = 0;
	p = -1;
	while (str[j])
	{
		if (str[j] == '.')
		{
			list->prec = -1;
			p = j;
		}
		j++;
	}
	if (p != -1 && str[p + 1] >= '0' && str[p + 1] <= '9')
		list->prec = ft_printf_atoi(str, p + 1);
	if (str[p + 1] == '*' && p != -1)
		list->prec = -1;
}

int			ft_length_find(char *str, int j, int max)
{
	if (max == 4)
		return (6);
	else if (max == 3)
		return (5);
	else if (max == 2)
	{
		while (str[j] != 'l')
			j++;
		if (ft_check_how_many(str, 0, 'l') == 0)
			return (4);
		else
			return (3);
	}
	else if (max == 1)
	{
		if (ft_check_how_many(str, 0, 'h') == 1)
			return (2);
		else
			return (1);
	}
	return (0);
}

void		ft_check_length(char *str, t_desc *list)
{
	int		max;
	int		j;

	max = 0;
	j = 0;
	while (str[j])
	{
		if ('z' == str[j])
			max = 4;
		if ('j' == str[j])
			if (max < 3)
				max = 3;
		if ('l' == str[j])
			if (max < 2)
				max = 2;
		if ('h' == str[j])
			if (max < 1)
				max = 1;
		j++;
	}
	list->length = ft_length_find(str, 0, max);
}
