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
std::map<std::string, std::string> Game::menu = {
	{"header", "Nibbler"},
	{"menu1", "Play"},
	{"menu2", "Multiplayer (local)"},
	{"menu3", "Exit"},
	{"footer", "@atilegen\'s team"}
};


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
	mainMenu();
}

void	Game::mainMenu(void)
{
	clear();
	state = 3;
	map = new Map();
	map->loadMap(mapSize.x, mapSize.y);

	auto &nibbler(Game::manager.addEntity());
	auto &play(Game::manager.addEntity());
	auto &scores(Game::manager.addEntity());
	auto &exit(Game::manager.addEntity());
	auto &author(Game::manager.addEntity());

	nibbler.addComponent<TransformComponent>(mapSize.x * Game::cellSize / 2, 2 * Game::cellSize, 0, 0);
	nibbler.addComponent<SpriteComponent>("header");
	nibbler.addGroup(group_ui);

	play.addComponent<TransformComponent>(mapSize.x * Game::cellSize / 2, (mapSize.y - 2) * Game::cellSize / 2, 0, 0);
	play.addComponent<SpriteComponent>("menu1");
	play.addGroup(group_ui);

	scores.addComponent<TransformComponent>(mapSize.x * Game::cellSize / 2, (mapSize.y) * Game::cellSize / 2, 0, 0);
	scores.addComponent<SpriteComponent>("menu2");
	scores.addGroup(group_ui);

	exit.addComponent<TransformComponent>(mapSize.x * Game::cellSize / 2, (mapSize.y + 2) * Game::cellSize / 2, 0, 0);
	exit.addComponent<SpriteComponent>("menu3");
	exit.addGroup(group_ui);

	author.addComponent<TransformComponent>(mapSize.x * Game::cellSize / 2, (mapSize.y - 2) * Game::cellSize, 0, 0);
	author.addComponent<SpriteComponent>("footer");
	author.addGroup(group_ui);

	backgrounds = &manager.getGroup(group_map);
	players = &manager.getGroup(group_player);
	foods = &manager.getGroup(group_food);
	colliders = &manager.getGroup(group_colliders);
	ui = &manager.getGroup(group_ui);
}

void	Game::start(int newState)
{
	clear();
	state = newState;
	map = new Map();
	map->loadMap(mapSize.x, mapSize.y);
	addSnake(&player, mapSize.x / 2, mapSize.y / 2, 2, 1);
	
	player2 = NULL;
	if (state == 4)
		addSnake(&player2, mapSize.x / 2, (mapSize.y + 2) / 2, 2, 2);

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
		if (control == menu1 || (state == 2 && control == space))
			start(1);
		else if (control == menu2)
			start(4);
		else if (control == menu3)
			is_running = false;
		else if ((state == 1 || state == 4))
		{
			if (control == right1 || control == left1 || control == up1 || control == down1)
				player->getComponent<Snake>().setDir(control);
			else if ((control == right2 || control == left2 || control == up2 || control == down2) && player2)
				player2->getComponent<Snake>().setDir(control);
		}
		if (control == escape)
				mainMenu();
	}
	cycle++;
}

void	Game::checkSnakes(Entity **s1, Entity **s2)
{
	std::deque<Vector2D>	body1 = (*s1)->getComponent<Snake>().body;
	std::deque<Vector2D>	body2 = (*s2)->getComponent<Snake>().body;
    Vector2D				snakeHead1 = (*s1)->getComponent<Snake>().body.front();
    Vector2D				snakeHead2 = (*s2)->getComponent<Snake>().body.front();

    if (snakeHead1.x == snakeHead2.x && snakeHead1.y == snakeHead2.y)
    {	
    	return ;
    }
    for (int i = 0; i < body2.size(); i++)
    	if (body2[i].x == snakeHead1.x && body2[i].y == snakeHead1.y)
    	{
    		foodSpawner->getComponent<FoodSpawner>().addFood(body2, i);
    		(*s2)->getComponent<Snake>().cut(i);
    	}

    for (int i = 0; i < body1.size(); i++)
    	if (body1[i].x == snakeHead2.x && body1[i].y == snakeHead2.y)
    	{
    		foodSpawner->getComponent<FoodSpawner>().addFood(body1, i);
    		(*s2)->getComponent<Snake>().cut(i);
    	}
}

void	Game::update(void)
{
	manager.refresh();
	if (state != 1 && state != 4)
		return ;
	manager.update();
	checkSnake(player);
	if (state == 4)
	{
		checkSnake(player2);
		checkSnakes(&player, &player2);
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
		frameWork->drawScore(player->getComponent<Snake>().score, player->getComponent<Snake>().id,
							mapSize.x * cellSize / 2, y + cellSize * 3);
		if (player2)
			frameWork->drawScore(player2->getComponent<Snake>().score, player2->getComponent<Snake>().id,
								mapSize.x * cellSize / 2, y + cellSize * 4);

	}
	frameWork->render();
}

void	Game::addCrash(int x, int y)
{
	auto &cell(manager.addEntity());
	cell.addComponent<TransformComponent>(x, y, cellSize, cellSize);
	cell.addComponent<SpriteComponent>("crash");
	cell.addGroup(group_colliders);
	state = 2;
}

void	Game::addSnake(Entity **p, int x, int y, int len, int id)
{
	*p = &manager.addEntity();
	(*p)->addComponent<Snake>(x, y, len, id);
	(*p)->addGroup(group_player);
}

void	Game::checkSnake(Entity *snake)
{
    std::deque<Vector2D>	body = snake->getComponent<Snake>().body;
    Vector2D				snakeHead = snake->getComponent<Snake>().body.front();
    Vector2D				pos;
    for (auto i = body.begin(); i != body.end(); i++)
    	for (auto j = body.begin(); j != body.end(); j++)
    		if (i != j && i->x == j->x && i->y == j->y)
			{
				addCrash(i->x, i->y);
				break ;
			}
	for (auto &f: *foods)
    {
    	pos = f->getComponent<TransformComponent>().position;
    	if (pos.x == snakeHead.x && pos.y == snakeHead.y)
    	{
    		foodSpawner->getComponent<FoodSpawner>().destroyFood(f);
    		snake->getComponent<Snake>().addTail();
    		break;
    	}
    }
    for (auto &c: *colliders)
    {
    	pos = c->getComponent<TransformComponent>().position;
    	if (pos.x == snakeHead.x && pos.y == snakeHead.y)
    	{
			addCrash(pos.x, pos.y);
			break ;
    	}
    }
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