/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:21:52 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/02/23 16:21:54 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putwstr_fd(char **s, int fd)
{
	int	i;
	int	j;

	i = 0;
	if (s)
		while (s[i])
		{
			j = 0;
			while (s[i][j] != '\0')
			{
				ft_putchar_fd(s[i][j], fd);
				j++;
			}
			i++;
		}
}

int		ft_wstrlen(char **str)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (str[i])
	{
		tmp += ft_strlen(str[i]);
		i++;
	}
	return (tmp);
}

void	ft_put_zero_fd(int size, int fd)
{
	int	j;

	j = 0;
	while (j < size)
	{
		ft_putchar_fd('0', fd);
		j++;
	}
}
