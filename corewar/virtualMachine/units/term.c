/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 14:25:21 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/31 14:25:21 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void				ft_usage(void)
{
	ft_printf("Usage: ./corewar [-dump nbr_cycles | -vis]");
	ft_printf("[-a] [[-n number] champion1.cor] ...\n");
	ft_printf("\t-a            : Prints output from \"aff\"");
	ft_printf("(Default is to hide it)\n");
	ft_printf("#### TEXT OUTPUT MODE ######################");
	ft_printf("####################################\n");
	ft_printf("\t-dump N       : Dumps memory after N cycles");
	ft_printf("then exits\n");
	ft_printf("#### NCURSES OUTPUT MODE ####################");
	ft_printf("###################################\n");
	ft_printf("\t-vis N        : Ncurses output mode\n");
	ft_printf("\t-aud	       : Add audio to visualization\n");
	ft_printf("#############################################");
	ft_printf("###################################\n");
	exit(0);
}

void				intro_players(t_game game)
{
	int	i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (game.p[i].size != -1 && i < MAX_PLAYERS)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", i + 1,
					game.p[i].size, game.p[i].bot_name, game.p[i].bot_comment);
		i++;
	}
}

int					check_flags(t_game *game, char **av)
{
	int	i;

	i = 0;
	while (av[++i] && (ft_strequ(av[i], "-dump") ||
ft_strequ(av[i], "-vis") || ft_strequ(av[i], "-a") || ft_strequ(av[i], "-aud")))
	{
		if (ft_strequ(av[i], "-dump"))
		{
			(!(*game).vis) ? (*game).dump = 1 : 0;
			(!ft_strdigit(av[++i])) ? ft_usage() : NULL;
			(*game).dump_n = ft_atoi(av[i]);
			((*game).dump_n < 0) ? ft_error("-dump Negative number") : 0;
		}
		else if (ft_strequ(av[i], "-vis"))
		{
			(*game).dump = 0;
			(*game).vis = 1;
			(!ft_strdigit(av[++i])) ? ft_usage() : NULL;
			(*game).vis_n = ft_atoi(av[i]);
			((*game).vis_n < 0) ? ft_error("-vis Negative number") : 0;
		}
		(ft_strequ(av[i], "-a")) ? (*game).aff = 1 : 0;
		(ft_strequ(av[i], "-aud")) ? (*game).audio = 1 : 0;
	}
	return (i);
}

int					validate_ids(t_game game)
{
	int	i;
	int	j;

	i = 0;
	while (game.p[i].size != -1 && i < MAX_PLAYERS)
	{
		j = 0;
		while (game.p[j].size != -1 && j < MAX_PLAYERS)
		{
			if (i != j && game.player_ids[i] == game.player_ids[j])
				ft_error("Error: same id\'s given");
			j++;
		}
		i++;
	}
	return (1);
}

int					get_players_nums(t_game *game, int i, char **av)
{
	int	players;
	int	k;
	int	j;

	k = 0;
	j = 1;
	players = 0;
	while (av[i])
	{
		if (ft_strequ(av[i], "-n"))
		{
			(!ft_strdigit(av[++i])) ? ft_usage() : NULL;
			(*game).player_ids[k++] = ft_atoi(av[i]);
			players++;
			i++;
		}
		else
		{
			(*game).player_ids[k++] = -j;
			j++;
			players++;
		}
		i++;
	}
	return (players);
}
