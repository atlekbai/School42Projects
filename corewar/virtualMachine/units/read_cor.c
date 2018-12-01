/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 14:26:51 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/15 14:26:52 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	print_cor(t_code code)
{
	int j;

	j = 0;
	while (++j <= code.size)
	{
		(code.code[j - 1] < 16) ? ft_putchar('0') : NULL;
		ft_printf("%x", code.code[j - 1]);
		(j % 2 == 0) ? ft_putchar(' ') : NULL;
		(j % 16 == 0) ? ft_putchar('\n') : NULL;
	}
	ft_putchar('\n');
}

int		cor_end(char *f)
{
	char *temp;

	temp = ft_strstr(f, ".cor");
	if (!temp || ft_strlen(temp) != 4)
		return (0);
	return (1);
}

t_code	read_cor(char *filename)
{
	int		fd;
	int		ret;
	t_byte	buf[BUFF_SIZE];
	t_code	code;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || !cor_end(filename))
	{
		system("say -v Daniel 'File error'&");
		ft_error("File error");
	}
	code.size = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		code.code[code.size++] = buf[0];
	close(fd);
	return (code);
}
