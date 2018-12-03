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
int			Game::state = 1;
int			Game::cellSize;
Vector2D	Game::mapSize;

Game::Game(void){}

Game::~Game(void)
{
	clear();
	frameWork->close();
}

void	Game::init(const char *title, int width, int height)
{
	frameWork = new SDLFramework();
	frameWork->init(title, width, height);
	is_running = true;
	cellSize = 32;
	mapSize = {width / cellSize, height / cellSize};
	start();
}

void	Game::start(void)
{
	map = new Map();
	map->loadMap(mapSize.x, mapSize.y);

	player = &manager.addEntity();
	player->addComponent<Snake>(mapSize.x / 2, mapSize.y / 2, 2);
	player->addGroup(group_player);

	foodSpawner = &manager.addEntity();
	foodSpawner->addComponent<FoodSpawner>(&player->getComponent<Snake>().body);

	backgrounds = &manager.getGroup(group_map);
	players = &manager.getGroup(group_player);
	foods = &manager.getGroup(group_food);
	colliders = &manager.getGroup(group_colliders);
	ui = &manager.getGroup(group_ui);
}

void	Game::clear(void)
{
	delete (map);
	manager.clear();
}

void	Game::handleEvents(void)
{
	static unsigned wait = 5;
	static unsigned cycle = 0;
	int control;

	if (cycle == wait)
	{
		cycle = 0;
		control = frameWork->handleEvents();
		if (state == 2 && control == -1)
		{
			clear();
			start();
			state = 1;
		}
		else if (state == 1 && (control == 1 || control == 2 || control == 3 || control == 4))
			player->getComponent<Snake>().setDir(control);
	}
	cycle++;
}

void	Game::update(void)
{
	manager.refresh();
	if (state == 2)
		return ;
	manager.update();

    std::deque<Vector2D> body = player->getComponent<Snake>().body;
    Vector2D	snakeHead = player->getComponent<Snake>().body.front();
    Vector2D	pos;

    for (auto i = body.begin(); i != body.end(); i++)
    	for (auto j = body.begin(); j != body.end(); j++)
    		if (i != j && i->x == j->x && i->y == j->y)
			{
				auto &cell(Game::manager.addEntity());
				cell.addComponent<TransformComponent>(i->x, i->y, cellSize, cellSize);
				cell.addComponent<SpriteComponent>("crash");
				cell.addGroup(group_ui);
				state = 2;
				break ;
			}

    for (auto &f: *foods)
    {
    	pos = f->getComponent<TransformComponent>().position;
    	if (pos.x == snakeHead.x && pos.y == snakeHead.y)
    	{
    		foodSpawner->getComponent<FoodSpawner>().destroyFood(f);
    		player->getComponent<Snake>().addTail();
    		break;
    	}
    }

    for (auto &c: *colliders)
    {
    	pos = c->getComponent<TransformComponent>().position;
    	if (pos.x == snakeHead.x && pos.y == snakeHead.y)
    	{
    		auto &cell(Game::manager.addEntity());
			cell.addComponent<TransformComponent>(pos.x, pos.y, cellSize, cellSize);
			cell.addComponent<SpriteComponent>("crash");
			cell.addGroup(group_ui);
			state = 2;
			break ;
    	}
    }
}

void	Game::render(void)
{
	frameWork->clear();
	for (auto &b: *backgrounds)
		b->draw();
	for (auto &p: *players)
		p->draw();
	for (auto &c: *colliders)
		c->draw();
	for (auto &f: *foods)
		f->draw();
	for (auto &u: *ui)
		u->draw();
	if (state == 2)
	{
		Rect src = {0, 0, 365, 65};
		int x = (mapSize.x * cellSize - src.w) / 2;
		int y = (mapSize.y * cellSize - src.h) / 2;
		Rect dst = {x, y, 365, 65};
		frameWork->draw("game_over", src, dst, 0);
	}
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
