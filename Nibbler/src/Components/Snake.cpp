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

static int		getAngle(int dir)
{
	if (dir == 2)
		return (180);
	else if (dir == 3)
		return (-90);
	else if (dir == 4)
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

void	Snake::setDir(int newDir)
{
	dir = newDir;
	cycle = 100;
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
	body.erase(body.begin() + i, body.end());
}


void	Snake::update(void)
{
	static unsigned wait = 100;
	if (cycle == wait)
	{
		cycle = 0;
		if (dir == right1 || dir == right2)
		{
			dir = 1;
			go_right();
		}
		else if (dir == left1 || dir == left2)
		{
			dir = 2;
			go_left();
		}
		else if (dir == up1 || dir == up2)
		{
			dir = 3;
			go_up();
		}
		else if (dir == down1 || dir == down2)
		{
			dir = 4;
			go_down();
		}
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