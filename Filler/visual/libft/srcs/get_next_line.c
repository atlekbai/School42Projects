/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skavunen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:57:25 by skavunen          #+#    #+#             */
/*   Updated: 2017/01/25 12:31:51 by skavunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_files				*ft_createlist(t_files *s, int count, int fd)
{
	t_files			*d;
	int				a;

	a = -1;
	if (!s)
	{
		d = (t_files*)malloc(sizeof(t_files));
		d[0].file = fd;
		d[0].last = 1;
	}
	else
	{
		d = (t_files*)malloc(sizeof(t_files) * count + 1);
		while (++a < count)
		{
			d[a].text = ft_strjoin(ft_strnew(0), s[a].text);
			d[a].file = s[a].file;
			d[a].last = 0;
		}
		d[a].file = fd;
		d[a].text = ft_strnew(0);
		d[a].last = 1;
		free(s);
	}
	return (d);
}

int					ft_readfile(char **d, int fd)
{
	char			*s;
	char			*buf;
	int				i;

	s = ft_strnew(BUFF_SIZE);
	i = read(fd, s, BUFF_SIZE);
	if (i < 0)
		return (-1);
	else if (i == 0)
		return (0);
	buf = *d;
	*d = ft_strjoin(*d, s);
	free(buf);
	free(s);
	return (1);
}

int					ft_nextline(char **d, char **line)
{
	char			*l;
	char			*s;
	int				i;

	i = 0;
	s = *d;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
		{
			l = ft_strsub(s, 0, i);
			*line = l;
			*d = ft_strsub(*d, i + 1, ft_strlen(*d) - i);
			free(s);
			return (1);
		}
		i++;
	}
	return (0);
}

int					ft_nextread(char **d, int fd, char **line)
{
	int				i;

	i = ft_nextline(d, line);
	if (i == 0)
	{
		while (ft_nextline(d, line) == 0)
		{
			i = ft_readfile(d, fd);
			if (i < 0)
				return (-1);
			else if (i == 0)
			{
				if (ft_strlen(*d) > 0)
				{
					*line = ft_strsub(*d, 0, ft_strlen(*d));
					*d = ft_strnew(0);
					return (1);
				}
				return (0);
			}
		}
		return (1);
	}
	else
		return (1);
}

int					get_next_line(int fd, char **line)
{
	static t_files	*d;
	int				a;
	int				i;

	a = 0;
	i = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	if (!d)
	{
		d = ft_createlist(d, a, fd);
		d[0].text = ft_strnew(0);
	}
	while (d[a].text)
	{
		if (d[a].file == fd)
		{
			i = ft_nextread(&d[a].text, fd, line);
			return (i);
		}
		else if (d[a].last == 1)
			d = ft_createlist(d, a + 1, fd);
		a++;
	}
	return (1);
}
