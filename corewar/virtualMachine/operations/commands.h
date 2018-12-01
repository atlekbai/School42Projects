/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:10:46 by atlekbai          #+#    #+#             */
/*   Updated: 2018/05/19 16:11:02 by atlekbai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "../header.h"

int			and(t_byte **map, t_proc **procs, t_game *game);
int			sti(t_byte **map, t_proc **procs, t_game *game);
int			live(t_byte **map, t_proc **procs, t_game *game);
int			zjmp(t_byte **map, t_proc **procs, t_game *game);
int			st(t_byte **map, t_proc **procs, t_game *game);
int			ld(t_byte **map, t_proc **procs, t_game *game);
int			frk(t_byte **map, t_proc **procs, t_game *game);
int			or(t_byte **map, t_proc **procs, t_game *game);
int			xor(t_byte **map, t_proc **procs, t_game *game);
int			sub(t_byte **map, t_proc **procs, t_game *game);
int			add(t_byte **map, t_proc **procs, t_game *game);
int			ldi(t_byte **map, t_proc **procs, t_game *game);
int			lldi(t_byte **map, t_proc **procs, t_game *game);
int			lld(t_byte **map, t_proc **procs, t_game *game);
int			lfrk(t_byte **map, t_proc **procs, t_game *game);
int			aff(t_byte **map, t_proc **procs, t_game *game);

#endif
