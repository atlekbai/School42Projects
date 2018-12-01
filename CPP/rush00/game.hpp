// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   game.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 21:04:33 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/23 21:04:34 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAME_HPP
# define GAME_HPP

#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "GameEntity.class.hpp"
#include "ThingGroup.hpp"
#include "Player.class.hpp"
#include "Position.class.hpp"
#include "Rect.hpp"
#include "Enemy.hpp"
#include "Boss.hpp"
#include "EnemySwarm.hpp"

int		init(WINDOW **main_window, WINDOW **game_window, Rect &screen_s, Rect &game_s);
void	run();
void	close();
int		renderPlayer(int frame, WINDOW *win, Player &player);
int		display(SpaceThing **obj, int n, WINDOW *win, char c);
int  	display(Bullet **obj, int n, WINDOW *win, char c);
int		actionObject(ThingGroup &field, int n, char c, int frame, WINDOW *win);
int 	stopGame(char const *text, WINDOW *win);
int 	renderEnemy(int frame, WINDOW *win, Enemy &enemy);
int 	renderBoss(int frame, WINDOW *win, Boss &boss);

#endif
