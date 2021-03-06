// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Snake.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/02 19:35:27 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/02 19:35:27 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

# include "Snake.hpp"
# include "Game.hpp"
# define WAIT 10

Snake::Snake(int x, int y, int length, int i, int c1, int c2, int c3, int c4)
{
	id = i;
	for (int i = 0; i < length; i++)
		body.push_back({(x - i) * Game::cellSize, y * Game::cellSize});
	
	controller.emplace(c1, &Snake::go_right);
	controller.emplace(c2, &Snake::go_left);
	controller.emplace(c3, &Snake::go_up);
	controller.emplace(c4, &Snake::go_down);
	d1 = c1;
	d2 = c2;
	d3 = c3;
	d4 = c4;

	dir = c1;
	cycle = 0;
	score = 0;
}

static void	drawPart(std::string id, int x, int y, double angle, int i)
{
	Rect src;
	Rect dst;

	src = {0, 0, 64, 64};
	dst = {x, y, Game::cellSize, Game::cellSize};
	if (i == 2)
		id += '2';
	Game::frameWork->draw(id, src, dst, angle);
}

int		Snake::getAngle(int dir)
{
	if (dir == d2)
		return (180);
	else if (dir == d3)
		return (-90);
	else if (dir == d4)
		return (90);
	return (0);
}

static Vector2D	getWay(Vector2D v1, Vector2D v2)
{
	Vector2D way = {(v1.x - v2.x) / Game::cellSize, (v1.y - v2.y) / Game::cellSize};
	return (way);
}

void	Snake::draw(void)
{
	Vector2D wayF;
	Vector2D wayB;
	int i = 0;

	drawPart("snake_head", body[0].x, body[0].y, getAngle(dir), id);

	for (i = 1; i < body.size() - 1; i++)
	{
		wayF = body[i - 1];
		wayB = body[i + 1];
		if (wayF.x == wayB.x && wayF.y == wayB.y)
			drawPart("snake_body", body[i].x, body[i].y, getAngle(dir), id);
		else if (wayB.x == wayF.x)
			drawPart("snake_body", body[i].x, body[i].y, 90, id);
		else if (wayB.y == wayF.y)
			drawPart("snake_body", body[i].x, body[i].y, 0, id);
		else if ((wayF.x > wayB.x && wayF.y < wayB.y && wayF.y == body[i].y) ||
				(wayF.x < wayB.x && wayF.y > wayB.y && wayF.x == body[i].x))
			drawPart("snake_edge", body[i].x, body[i].y, 0, id);
		else if ((wayF.x < wayB.x && wayF.y < wayB.y && wayF.y == body[i].y) ||
				(wayF.x > wayB.x && wayF.y > wayB.y && wayF.x == body[i].x))
			drawPart("snake_edge", body[i].x, body[i].y, 90, id);
		else if ((wayF.x < wayB.x && wayF.y > wayB.y && wayF.y == body[i].y) || 
				(wayF.x > wayB.x && wayF.y < wayB.y && wayF.x == body[i].x))
			drawPart("snake_edge", body[i].x, body[i].y, 180, id);
		else if (wayF.x > wayB.x && wayF.y > wayB.y && wayF.y == body[i].y)
			drawPart("snake_edge", body[i].x, body[i].y, 270, id);
		else if (wayF.x < wayB.x && wayF.y < wayB.y)
			drawPart("snake_edge", body[i].x, body[i].y, 270, id);
		else if (wayF.x > wayB.x && wayF.y < wayB.y)
			drawPart("snake_edge", body[i].x, body[i].y, 180, id);
	}
	if (body.size() == 1)
		return ;
	wayF = body[i - 1];
	if (wayF.x == body[i].x)
	{
		if (wayF.y > body[i].y)
			drawPart("snake_tail", body[i].x, body[i].y, 90, id);
		else
			drawPart("snake_tail", body[i].x, body[i].y, 270, id);
	}
	else if (wayF.y == body[i].y)
	{
		if (wayF.x > body[i].x)
			drawPart("snake_tail", body[i].x, body[i].y, 0, id);
		else
			drawPart("snake_tail", body[i].x, body[i].y, 180, id);
	}
}

bool	Snake::setDir(int newDir)
{
	if (newDir == d1 || newDir == d2 || newDir == d3 || newDir == d4)
	{
		if ((dir == d1 && newDir == d2) ||
			(dir == d2 && newDir == d1) ||
			(dir == d3 && newDir == d4) ||
			(dir == d4 && newDir == d3))
			return (false);
		dir = newDir;
		cycle = WAIT;
		return (true);
	}
	return (false);
}

void	Snake::addTail(void)
{
	int x, y;
	Vector2D wayF = body[body.size() - 2];
	Vector2D wayB = body[body.size() - 1];

	if (wayF.y == wayB.y)
	{
		x = (wayB.x > wayF.x) ? wayB.x + Game::cellSize : wayB.x - Game::cellSize;
		y = wayB.y;
	}
	else if (wayF.x == wayB.x)
	{
		x = wayB.x;
		y = (wayB.y > wayF.y) ? wayB.y + Game::cellSize : wayB.y - Game::cellSize;
	}
	body.push_back({x, y});
	score++;
}

void	Snake::cut(int i)
{
	score -= body.size() - i;
	body.erase(body.begin() + i, body.end());
}

void	Snake::update(void)
{
	static unsigned wait = WAIT;
	if (cycle == wait)
	{
		cycle = 0;
		(this->*controller[dir])();
	}
	cycle++;
}

void	Snake::go_right(void)
{
	body.pop_back();
	Vector2D p = body.front();
	body.push_front({p.x + Game::cellSize, p.y});
}

void	Snake::go_up(void)
{
	body.pop_back();
	Vector2D p = body.front();
	body.push_front({p.x, p.y - Game::cellSize});
}

void	Snake::go_left(void)
{
	body.pop_back();
	Vector2D p = body.front();
	body.push_front({p.x - Game::cellSize, p.y});
}

void	Snake::go_down(void)
{
	body.pop_back();
	Vector2D p = body.front();
	body.push_front({p.x, p.y + Game::cellSize});
}