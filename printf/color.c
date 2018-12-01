/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:28:13 by atlekbai          #+#    #+#             */
/*   Updated: 2018/04/18 12:28:14 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	color(char const **str, int size, char *color)
{
	*str += size;
	ft_putstr(color);
}

void	color_usual(char const **str)
{
	if (ft_strncmp(*str, "[#green]", 8) == 0)
		color(str, 7 + 1, "\033[0;32m");
	if (ft_strncmp(*str, "[#white]", 8) == 0)
		color(str, 7 + 1, "\033[0;37m");
	if (ft_strncmp(*str, "[#black]", 8) == 0)
		color(str, 7 + 1, "\033[0;30m");
	if (ft_strncmp(*str, "[#red]", 6) == 0)
		color(str, 5 + 1, "\033[0;31m");
	if (ft_strncmp(*str, "[#yellow]", 9) == 0)
		color(str, 8 + 1, "\033[0;33m");
	if (ft_strncmp(*str, "[#blue]", 7) == 0)
		color(str, 6 + 1, "\033[0;34m");
	if (ft_strncmp(*str, "[#purple]", 9) == 0)
		color(str, 8 + 1, "\033[0;35m");
	if (ft_strncmp(*str, "[#cyan]", 7) == 0)
		color(str, 6 + 1, "\033[0;36m");
	if (ft_strncmp(*str, "[#eoc]", 6) == 0)
		color(str, 5 + 1, "\033[0;37m");
}

void	color_bold(char const **str)
{
	if (ft_strncmp(*str, "[#bgreen]", 8 + 1) == 0)
		color(str, 7 + 2, "\033[1;32m");
	if (ft_strncmp(*str, "[#bwhite]", 8 + 1) == 0)
		color(str, 7 + 2, "\033[1;37m");
	if (ft_strncmp(*str, "[#bblack]", 8 + 1) == 0)
		color(str, 7 + 2, "\033[1;30m");
	if (ft_strncmp(*str, "[#bred]", 6 + 1) == 0)
		color(str, 5 + 2, "\033[1;31m");
	if (ft_strncmp(*str, "[#byellow]", 9 + 1) == 0)
		color(str, 8 + 2, "\033[1;33m");
	if (ft_strncmp(*str, "[#bblue]", 7 + 1) == 0)
		color(str, 6 + 2, "\033[1;34m");
	if (ft_strncmp(*str, "[#bpurple]", 9 + 1) == 0)
		color(str, 8 + 2, "\033[1;35m");
	if (ft_strncmp(*str, "[#bcyan]", 7 + 1) == 0)
		color(str, 6 + 2, "\033[1;36m");
}
