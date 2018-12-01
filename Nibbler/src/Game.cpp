// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Game.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/24 19:26:57 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/24 19:26:58 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Game.hpp"
#include "SDLFramework.hpp"
#include "Components.hpp"
#include "Map.hpp"

Manager		Game::manager;
Framework	*Game::frameWork;
Map			*Game::map;
bool		Game::is_running = false;
int			Game::cellSize;
Vector2D	Game::mapSize;

Game::Game(void){}

Game::~Game(void)
{
	frameWork->close();
}

void	Game::init(const char *title, int width, int height)
{
	frameWork = new SDLFramework();
	frameWork->init(title, width, height);
	is_running = true;
	cellSize = 32;
	mapSize = {width / cellSize, height / cellSize};

	map = new Map();
	map->loadMap(mapSize.x, mapSize.y);

	player = &manager.addEntity();
	player->addComponent<Snake>(mapSize.x / 2, mapSize.y / 2, 5);
	player->addGroup(group_player);

	backgrounds = &manager.getGroup(group_map);
	players = &manager.getGroup(group_player);
	foods = &manager.getGroup(group_food);
	colliders = &manager.getGroup(group_colliders);
}

void	Game::handleEvents(void)
{
	/*
	**	1 - D, 2 - A, 3 - W, 4 - S
	*/
	int control = frameWork->handleEvents();
	if (control != 0)
		player->getComponent<Snake>().dir = control;
}

void	Game::update(void)
{
	manager.refresh();
    manager.update();
}

void	Game::render(void)
{
	frameWork->clear();

	for (auto &b: *backgrounds)
		b->draw();
	for (auto &p: *players)
		p->draw();
	for (auto &f: *foods)
		f->draw();
	for (auto &c: *colliders)
		c->draw();

	frameWork->render();
}

bool	Game::running(void) const
{
	return (is_running);
}

void	Game::delay(int time)
{
	frameWork->delay(time);
}

unsigned Game::ticks(void)
{
	return (frameWork->ticks());
}
