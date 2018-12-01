/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 16:20:02 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/15 16:20:02 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	bot_name(int j, t_code code, t_player *player)
{
	int hex;
	int i;

	hex = 0;
	while (++j < code.size && hex < PROG_NAME_LENGTH)
		(*player).bot_name[hex++] = code.code[j];
	if (hex != PROG_NAME_LENGTH)
	{
		system("say -v Daniel 'Wrong bot name'&");
		ft_error("Wrong bot name :(");
	}
	i = j;
	while (i < j + 4)
	{
		if (code.code[i] != 0)
		{
			system("say -v Daniel 'Wrong number of NULL bytes'&");
			ft_error("Wrong number of NULL bytes :(");
		}
		i++;
	}
	return (j);
}

static int	bot_size(int j, t_code code, t_player *player)
{
	int hex;
	int	i;
	int tmp_j;

	hex = -1;
	tmp_j = j + 1;
	(*player).size = 0;
	while (++j < code.size && ++hex < 4)
		(*player).size += ((*player).size << 8) | code.code[j];
	if (hex != 4 && !system("say -v Daniel 'Something goes wrong'&"))
		ft_error("Something goes wrong :(");
	hex = 3;
	i = 0;
	while (hex > -1)
	{
		(*player).size -= code.code[tmp_j + hex] * i;
		hex--;
		i++;
	}
	if ((*player).size > CHAMP_MAX_SIZE &&
			!system("say -v Daniel 'Too big champ size'&"))
		ft_error("Too big champ size :(");
	return (j);
}

static int	bot_comment(int j, t_code code, t_player *player)
{
	int hex;
	int i;

	hex = 0;
	while (j <= code.size && hex < COMMENT_LENGTH)
		(*player).bot_comment[hex++] = code.code[j++];
	if (hex != COMMENT_LENGTH)
	{
		system("say -v Daniel 'Wrong lenght of comments'&");
		ft_error("Wrong lenght of comments");
	}
	i = j;
	while (i < j + 4)
	{
		if (code.code[i] != 0)
		{
			system("say -v Daniel 'Wrong binary .cor'&");
			ft_error("Wrong binary .cor :(");
		}
		i++;
	}
	return (j);
}

static int	bot_code(int j, t_code code, t_player *player)
{
	int hex;
	int trash;

	hex = 0;
	trash = 0;
	(*player).exec_code = (t_byte *)malloc(sizeof(t_byte)
							* ((*player).size + 1));
	while (j < code.size && code.code[j] == 0)
	{
		trash++;
		j++;
	}
	while (j < code.size && hex < (*player).size)
	{
		(*player).exec_code[hex++] = code.code[j++];
		trash++;
	}
	if (j != code.size || trash - 1 > (*player).size)
	{
		system("say -v Daniel 'This bot is with trash'&");
		ft_error("This bot is with trash :(");
	}
	(*player).exec_code[hex] = 0;
	return (j);
}

t_player	create_player(t_code code, int id)
{
	t_player	player;
	int			j;
	int			hex;

	hex = (code.code[1] << 16) | (code.code[2] << 8) | code.code[3];
	if (COREWAR_EXEC_MAGIC != hex || code.code[0] != 0)
		ft_error("MAGIC doesn\'t match");
	player.bot_name = ft_strnew(PROG_NAME_LENGTH);
	player.size = 0;
	player.id = id;
	player.last_live = 0;
	player.lives_cur = 0;
	player.alive = 1;
	player.bot_comment = ft_strnew(COMMENT_LENGTH);
	j = bot_name(3, code, &player) + 3;
	j = bot_size(j, code, &player);
	j = bot_comment(j, code, &player) + 3;
	j = bot_code(j, code, &player);
	return (player);
}
