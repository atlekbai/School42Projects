/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:20:08 by atilegen          #+#    #+#             */
/*   Updated: 2018/03/26 16:48:13 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "header.h"

#define BUFF 1000042

int		is_valid_map(char *str, int map_count)
{
	int	c;
	int	i;
	int	j;
	int	cnt;

	j = 0;
	c = 0;
	cnt = 0;
	while (j < map_count && *str)
	{
		i = -1;
		cnt = 0;
		while (++i < 20)
			if (str[i] == '#')
				touches(i, str, &c, &cnt);
		if ((c == 6 || c == 8) && cnt == 4)
		{
			str += 21;
			j++;
			c = 0;
		}
		else
			ft_error();
	}
	return (1);
}

int		***to_right_arr(char *str, int map_count)
{
	int		***arr;
	int		i;
	int		j;
	char	*temp;

	temp = str;
	if (!is_valid_map(temp, map_count))
		return (0);
	i = -1;
	arr = (int ***)malloc(sizeof(int **) * map_count);
	while (++i < map_count && *str)
	{
		j = -1;
		arr[i] = (int **)malloc(sizeof(int *) * 4);
		while (++j < 4)
		{
			arr[i][j] = (int *)malloc(sizeof(int) * 4);
			arr[i][j] = arr_unit(arr[i][j], &str);
			str++;
		}
		str++;
	}
	return (arr);
}

int		is_right_arr(char *str, int map_count)
{
	int len;

	len = ft_strlen(str) + 1;
	if (len == map_count * 20 + map_count)
	{
		to_right_arr(str, map_count);
		return (1);
	}
	ft_error();
	return (0);
}

t_map	ft_open(char **argv)
{
	int		fd;
	char	*str;
	int		j;
	char	buff[BUFF + 1];
	t_map	map;

	map.count = 0;
	j = 0;
	str = (char*)malloc(sizeof(*str) * (BUFF + 1));
	fd = open(argv[1], O_RDONLY);
	if (fd > 0)
	{
		while (read(fd, buff, 1) > 0)
			read_count(buff, str, &j, &map);
		str[j] = '\0';
		close(fd);
		if (is_right_arr(str, ++map.count))
		{
			map.map = to_right_arr(str, map.count);
			return (map);
		}
	}
	else
		ft_error();
	return (map);
}
