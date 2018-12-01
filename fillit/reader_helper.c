/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:37:34 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/30 18:37:36 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "header.h"

void	read_count(char buff[], char *str, int *j, t_map *map)
{
	int c;

	c = 0;
	if (is_valid_char(buff[0]) == 1)
	{
		str[*j] = buff[0];
		if (*j > 0 && str[*j] == '\n' && str[*j - 1] == '\n' &&
			str[*j] && *j == ((*map).count + 1) * 20 + (*map).count)
			(*map).count++;
	}
	else
		ft_error();
	*j = *j + 1;
}

int		*arr_unit(int *arr, char **str)
{
	int k;

	k = -1;
	while (++k < 4)
	{
		if (**str == '.')
			arr[k] = 0;
		else if (**str == '#')
			arr[k] = 1;
		*str = *str + 1;
	}
	return (arr);
}

int		is_valid_char(char c)
{
	if (c == '#' || c == '.' || c == '\n')
		return (1);
	return (0);
}

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	touches(int i, char *str, int *c, int *cnt)
{
	*cnt = *cnt + 1;
	if ((i + 1) < 20 && str[i + 1] == '#')
		*c = *c + 1;
	if ((i - 1) >= 0 && str[i - 1] == '#')
		*c = *c + 1;
	if ((i + 5) < 20 && str[i + 5] == '#')
		*c = *c + 1;
	if ((i - 5) >= 0 && str[i - 5] == '#')
		*c = *c + 1;
}
