/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdanylev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:40:44 by hdanylev          #+#    #+#             */
/*   Updated: 2017/11/04 12:59:13 by hdanylev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putendl_fd(char const *str, int fd)
{
	int i;

	if (str != NULL)
	{
		i = 0;
		while (str[i])
		{
			write(fd, &str[i], 1);
			i++;
		}
		write(fd, "\n", 1);
	}
}
