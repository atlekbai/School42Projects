/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 16:07:35 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/06 16:07:37 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	choose(t_way **chosen, t_way *paths, int *id)
{
	*chosen = paths;
	*id = *id - 1;
}

int		str_is_dgt(char *s)
{
	while (*s && *s != 32)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

t_info	info_set(char *name, int start, char *line)
{
	t_info info;

	info.name = name;
	info.start = start;
	if (!str_is_dgt(ft_strchr(line, 32) + 1))
		ft_err();
	if (!str_is_dgt(ft_strchr(ft_strchr(line, 32) + 1, 32) + 1))
		ft_err();
	info.x = ft_atoi(ft_strchr(line, 32) + 1);
	info.y = ft_atoi(ft_strchr(ft_strchr(line, 32) + 1, 32) + 1);
	return (info);
}

void	ft_err(void)
{
	ft_printf("ERROR\n");
	exit(0);
}

void	out_n_free(char **line)
{
	ft_putendl(*line);
	free(*line);
}
