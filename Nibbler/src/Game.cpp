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

Framework	*Game::frameWork = nullptr;
Map			*Game::map = nullptr;
GUI			*Game::gui = nullptr;
Network		Game::net;
bool		Game::is_running = false;
int			Game::state = 1;
int			Game::cellSize;
Manager		Game::manager;
Vector2D	Game::mapSize;
int			Game::cs;

void	Game::addFramework(Framework* f)
{
	frameWorks.push_back(f);
}

void	Game::sendNet(int command)
{
	int res;

	buf[0] = command;
	res = send(cs, buf, 2, 0);
	if (res == -1)
	{
		std::cout << "player disconnected" << std::endl;
		state = 3;
	}
}

int		Game::recvNet(void)
{
	int n;
	int res;

	struct timeval tv;
	tv.tv_sec = 2;
	tv.tv_usec = 0;
	setsockopt(cs, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);


	res = recv(cs, buf, 2, 0);
	std::cout << res << std::endl;
	if (res == -1)
	{
		std::cout << "player disconnected" << std::endl;
		state = 3;
	}
	n = static_cast<int>(buf[0]);
	return (n);
}

void	Game::netGame(void)
{
	state = 5;
	cs = net.serverLoad();
	start(state);
}

void	Game::clientGame(void)
{
	std::string ip;
	std::cout << "enter ip address of server: ";
	std::getline(std::cin, ip);

	state = 6;
	cs = net.clientConnect(ip);
	if (state == 3)
	{
		mainMenu();
		return ;
	}
	start(state);
}


Game::Game(void){}

Game::~Game(void)
{
	clear();
	close(cs);
	delete (map);
	frameWork->close();
}

void	Game::init(const char *title, int width, int height)
{
	frameWork = frameWorks[0];
	frameWork->init(title, width, height, GUI::menu);
	is_running = true;
	cellSize = 32;
	mapSize = {width / cellSize, height / cellSize};
	map = new Map();
	gui = new GUI();
	player = NULL;
	player2 = NULL;
	backgrounds = &manager.getGroup(group_map);
	players = &manager.getGroup(group_player);
	foods = &manager.getGroup(group_food);
	colliders = &manager.getGroup(group_colliders);
	ui = &manager.getGroup(group_ui);
	mainMenu();
}

void	Game::mainMenu(void)
{
	clear();
	state = 3;
	map->loadMap(mapSize.x, mapSize.y);
	gui->loadMenu();
}

void	Game::start(int newState)
{
	bool mainSpawner = (state == 6) ? false : true;
	clear();
	state = newState;
	map->loadMap(mapSize.x, mapSize.y);
	addSnake(&player, mapSize.x / 2, mapSize.y / 2, 4, 1);
	if (state == 4 || state == 5 || state == 6)
		addSnake(&player2, mapSize.x / 2, (mapSize.y + 4) / 2, 4, 2);
	foodSpawner = &manager.addEntity();
	foodSpawner->addComponent<FoodSpawner>(&player->getComponent<Snake>().body, mainSpawner);
	if (state == 6)
	{
		recv(cs, buf, 2, 0);
		foodSpawner->getComponent<FoodSpawner>().addFood(buf[0] * Game::cellSize,
													   	buf[1] * Game::cellSize);
	}
}

void	Game::clear(void)
{
	manager.clear();
	player = NULL;
	player2 = NULL;
}

void	Game::setFrame(int frameIndex)
{
	if (frameWork == frameWorks[frameIndex - frame1])
		return ;
	frameWork->close();
	frameWork = frameWorks[frameIndex - frame1];
	frameWork->init("Nibbler", mapSize.x * cellSize, mapSize.y * cellSize, GUI::menu);
}

void	Game::handleEvents(void)
{
	static unsigned	wait = 5;
	static unsigned	cycle = 0;
	int 			control = 0;
	int				netData = 0;

	control = frameWork->handleEvents(Game::manager.getGroup(group_ui));

	if (control == menu1)
		start(1);
	else if (control == menu2)
		start(4);
	else if (control == menu3)
		netGame();
	else if (control == menu4)
		clientGame();
	else if (control == menu5 || control == exit_event)
		is_running = false;
	else if (control == escape)
		mainMenu();
	if (control == frame1 || control == frame2 || control == frame3)
		setFrame(control);
	if (cycle == wait)
	{
		cycle = 0;
		if (state == 1 || state == 4 || state == 5)
			player->getComponent<Snake>().setDir(control);
		if (state == 5)
		{
			sendNet(control);
			netData = recvNet();		
			player2->getComponent<Snake>().setDir(netData);
		}
		if (state == 6)
		{
			sendNet(control);
			netData = recvNet();
			player->getComponent<Snake>().setDir(netData);
		}
	}
	if ((state == 4 || state == 6) && player2)
		player2->getComponent<Snake>().setDir(control);
	cycle++;
}

void	Game::update(void)
{
	manager.refresh();
	if (state != 1 && state != 4 && state != 5 && state != 6)
		return ;
	manager.update();
	checkSnake(player);
	if (state == 4 || state == 5 || state == 6)
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
		gui->gameOver();
		gui->addScore(player->getComponent<Snake>().score, player->getComponent<Snake>().id);
		if (player2)
			gui->addScore(player2->getComponent<Snake>().score, player2->getComponent<Snake>().id);
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
	if (id == 1)
		(*p)->addComponent<Snake>(x, y, len, id, right1, left1, up1, down1);
	else
		(*p)->addComponent<Snake>(x, y, len, id, right2, left2, up2, down2);
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

void	Game::checkSnakes(Entity **s1, Entity **s2)
{
	std::deque<Vector2D>	body1 = (*s1)->getComponent<Snake>().body;
	std::deque<Vector2D>	body2 = (*s2)->getComponent<Snake>().body;
    Vector2D				snakeHead1 = (*s1)->getComponent<Snake>().body.front();
    Vector2D				snakeHead2 = (*s2)->getComponent<Snake>().body.front();

    if (snakeHead1.x == snakeHead2.x && snakeHead1.y == snakeHead2.y)
    {	
    	addCrash(snakeHead1.x, snakeHead1.y);
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
    		(*s1)->getComponent<Snake>().cut(i);
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