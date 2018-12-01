/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvdovenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 18:35:18 by dvdovenk          #+#    #+#             */
/*   Updated: 2017/02/25 18:35:19 by dvdovenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_put_color2(char **tmp)
{
	tmp[18] = LIGHT_BLUE;
	tmp[19] = LIGHT_MAGENTA;
	tmp[20] = LIGHT_CYAN;
	tmp[21] = WHITE;
	tmp[22] = BLACK_BG;
	tmp[23] = RED_BG;
	tmp[24] = GREEN_BG;
	tmp[25] = YELLOW_BG;
	tmp[26] = BLUE_BG;
	tmp[27] = MAGENTA_BG;
	tmp[28] = CYAN_BG;
	tmp[29] = GRAY_BG;
	tmp[30] = DARK_GRAY_BG;
	tmp[31] = LIGHT_RED_BG;
	tmp[32] = LIGHT_GREEN_BG;
	tmp[33] = LIGHT_YELLOW_BG;
	tmp[34] = LIGHT_BLUE_BG;
	tmp[35] = LIGHT_MAGENTA_BG;
	tmp[36] = LIGHT_CYAN_BG;
	tmp[37] = WHITE_BG;
	tmp[38] = EOC;
	return (tmp);
}

void	ft_put_color(int i, char **set)
{
	char	**tmp;

	tmp = (char**)malloc(sizeof(char*) * 39);
	tmp[0] = BOLD;
	tmp[1] = DIM;
	tmp[2] = UNDERLINED;
	tmp[3] = BLINK;
	tmp[4] = INV;
	tmp[5] = HIDDEN;
	tmp[6] = BLACK;
	tmp[7] = RED;
	tmp[8] = GREEN;
	tmp[9] = YELLOW;
	tmp[10] = BLUE;
	tmp[11] = MAGENTA;
	tmp[12] = CYAN;
	tmp[13] = GRAY;
	tmp[14] = DARK_GRAY;
	tmp[15] = LIGHT_RED;
	tmp[16] = LIGHT_GREEN;
	tmp[17] = LIGHT_YELLOW;
	tmp = ft_put_color2(tmp);
	ft_putstr_fd(tmp[i], 2);
	ft_memdel((void*)&tmp);
	ft_memdel((void*)&set);
}

char	**init_colors2(char **tmp)
{
	tmp[20] = LIGHT_CYAN_COLOR;
	tmp[21] = WHITE_COLOR;
	tmp[22] = BLACK_BACK;
	tmp[23] = RED_BACK;
	tmp[24] = GREEN_BACK;
	tmp[25] = YELLOW_BACK;
	tmp[26] = BLUE_BACK;
	tmp[27] = MAGENTA_BACK;
	tmp[28] = CYAN_BACK;
	tmp[29] = GRAY_BACK;
	tmp[30] = DARK_GRAY_BACK;
	tmp[31] = LIGHT_RED_BACK;
	tmp[32] = LIGHT_GREEN_BACK;
	tmp[33] = LIGHT_YELLOW_BACK;
	tmp[34] = LIGHT_BLUE_BACK;
	tmp[35] = LIGHT_MAGENTA_BACK;
	tmp[36] = LIGHT_CYAN_BACK;
	tmp[37] = WHITE_BACK;
	tmp[38] = EOC_COLOR;
	return (tmp);
}

char	**init_colors(void)
{
	char	**tmp;

	tmp = (char**)malloc(sizeof(char*) * 39);
	tmp[0] = BOLD_DEF;
	tmp[1] = DIM_DEF;
	tmp[2] = UNDERLINED_DEF;
	tmp[3] = BLINK_DEF;
	tmp[4] = INV_DEF;
	tmp[5] = HIDDEN_DEF;
	tmp[6] = BLACK_COLOR;
	tmp[7] = RED_COLOR;
	tmp[8] = GREEN_COLOR;
	tmp[9] = YELLOW_COLOR;
	tmp[10] = BLUE_COLOR;
	tmp[11] = MAGENTA_COLOR;
	tmp[12] = CYAN_COLOR;
	tmp[13] = GRAY_COLOR;
	tmp[14] = DARK_GRAY_COLOR;
	tmp[15] = LIGHT_RED_COLOR;
	tmp[16] = LIGHT_GREEN_COLOR;
	tmp[17] = LIGHT_YELLOW_COLOR;
	tmp[18] = LIGHT_BLUE_COLOR;
	tmp[19] = LIGHT_MAGENTA_COLOR;
	tmp = init_colors2(tmp);
	return (tmp);
}

int		ft_set_color(const char *data, int pos, int i)
{
	char	*color;
	char	**set;
	int		len;

	i = pos;
	while (data[pos] && data[pos] != '}')
		pos++;
	color = ft_strsub(data, i, pos - i + 1);
	i = 0;
	set = init_colors();
	while (i < 39)
	{
		if (ft_strcmp(color, set[i]) == 0)
		{
			ft_put_color(i, set);
			len = ft_strlen(color);
			ft_strdel(&color);
			return (len);
		}
		i++;
	}
	ft_strdel(&color);
	ft_putchar('{');
	return (1);
}
