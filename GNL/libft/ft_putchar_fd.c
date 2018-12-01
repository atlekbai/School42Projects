/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:24:01 by atlekbai          #+#    #+#             */
/*   Updated: 2018/03/24 17:20:00 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	get_bytes(unsigned int c)
{
	if (c <= 127)
		return (1);
	else if (c >= 128 && c <= 2047)
		return (2);
	else if (c >= 2048 && c <= 65535)
		return (3);
	else if (c >= 65536 && c <= 2097151)
		return (4);
	return (-1);
}

void		ft_putchar_fd(unsigned int c, int fd)
{
	int				bytes;
	unsigned char	to_write[4];

	bytes = get_bytes(c);
	if (bytes == 1)
		to_write[0] = (char)c;
	else if (bytes == 2)
	{
		to_write[0] = (c >> 6) | 192;
		to_write[1] = (c & 63) | 128;
	}
	else if (bytes == 3)
	{
		to_write[0] = (c >> 12) | 224;
		to_write[1] = ((c >> 6) & 63) | 128;
		to_write[2] = (c & 63) | 128;
	}
	else if (bytes == 4)
	{
		to_write[0] = (c >> 18) | 240;
		to_write[1] = ((c >> 12) & 63) | 128;
		to_write[2] = ((c >> 6) & 63) | 128;
		to_write[3] = (c & 63) | 128;
	}
	write(fd, to_write, bytes);
}
