/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 19:48:56 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/13 19:49:22 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int					violin(t_game *game, int num)
{
	if ((*game).vis == 0 || (*game).vis_n > (*game).i || !(*game).audio)
		return (1);
	(num == 1) ? system("afplay sounds/D4_025.mp3&") : 0;
	(num == 2) ? system("afplay sounds/D5_025.mp3&") : 0;
	(num == 3) ? system("afplay sounds/E5_025.mp3&") : 0;
	(num == 4) ? system("afplay sounds/B2_025.mp3&") : 0;
	(num == 5) ? system("afplay sounds/B3_025.mp3&") : 0;
	(num == 6) ? system("afplay sounds/B4_025.mp3&") : 0;
	(num == 7) ? system("afplay sounds/B1_15.mp3&") : 0;
	(num == 8) ? system("afplay sounds/A1_15.mp3&") : 0;
	(num == 9) ? system("afplay sounds/G4_025.mp3&") : 0;
	(num == 10) ? system("afplay sounds/G4_025.mp3&") : 0;
	(num == 11) ? system("afplay sounds/G3_025.mp3&") : 0;
	(num == 12) ? system("afplay sounds/G1_05.mp3&") : 0;
	(num == 13) ? system("afplay sounds/A3_025.mp3&") : 0;
	(num == 15) ? system("afplay sounds/E5_025.mp3&") : 0;
	return (1);
}

void				print_aff(t_game game)
{
	int	i;

	i = -1;
	while (game.aff_arr[++i])
		ft_printf("Aff: %c\n", game.aff_arr[i]);
}

int					loading(t_game *game, int ac, char **av)
{
	int			n_players;
	int			i;
	int			j;

	init_game(game);
	(ac == 1) ? ft_usage() : NULL;
	i = check_flags(game, av);
	n_players = get_players_nums(game, i, av);
	j = 0;
	while (i < ac)
	{
		i += (ft_strequ(av[i], "-n")) ? 2 : 0;
		(j >= MAX_PLAYERS) ? ft_error("Too many champions") : 0;
		load_game(game, n_players, av[i++], j++);
	}
	(j == 0) ? ft_error("No players given") : 0;
	validate_ids(*game);
	system("say -v Daniel 'All right let\'s go&");
	return (1);
}

int					main(int ac, char **av)
{
	t_game		game;
	t_op		*op;

	loading(&game, ac, av);
	(!game.vis) ? intro_players(game) : NULL;
	reset_game(&game);
	if (game.vis)
	{
		print_text(game);
		print_start_map(&game, game.procs_arr);
	}
	op = command_struct();
	move_around(op, &game);
	(game.vis) ? game_over(game) : NULL;
	(game.aff) ? print_aff(game) : NULL;
	if (!game.vis && game.last_player > -1)
		ft_printf("Contestant %d, \"%s\", has won !\n",
			game.last_player + 1, game.p[game.last_player].bot_name);
	else if (game.last_player == -1)
		ft_printf("No winner\n");
	free(op);
	return (0);
}
