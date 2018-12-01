/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:27:34 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/19 16:27:34 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		get_player_by_id(t_player *players, unsigned int id)
{
	int i;

	i = -1;
	while (players[++i].size != -1 && i < MAX_PLAYERS)
		if (players[i].id == (int)id)
			return (i);
	return (-1);
}
