// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Snake.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/01 19:09:37 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/01 19:09:37 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SNAKE_HPP
# define SNAKE_HPP

# include "Game.hpp"
# include "Component.hpp"
# include <deque>

void	drawPart(std::string id, int x, int y, double angle)
{
	Rect src;
	Rect dst;

	src = {0, 0, 64, 64};
	dst = {x, y, Game::cellSize, Game::cellSize};
	Game::frameWork->draw(id, src, dst, angle);
}

int		getAngle(int dir)
{
	if (dir == 2)
		return (180);
	else if (dir == 3)
		return (-90);
	else if (dir == 4)
		return (90);
	return (0);
}

Vector2D	getWay(Vector2D v1, Vector2D v2)
{
	Vector2D way = {(v1.x - v2.x) / Game::cellSize, (v1.y - v2.y) / Game::cellSize};
	return (way);
}

class Snake: public Component
{
public:
	int						dir;
	std::deque<Vector2D>	body;
	Snake(int x, int y, int length)
	{
		for (int i = 0; i < length; i++)
			body.push_back({(x - i) * Game::cellSize, y * Game::cellSize});
		dir = 1;
	}

	void	draw(void) override
	{
		int i = 0;

		drawPart("snake_head", body[0].x, body[0].y, getAngle(dir));

		for (i = 1; i < body.size() - 1; i++)
		{
			Vector2D wayF = body[i - 1];
			Vector2D wayB = body[i + 1];
			
			if (wayB.x == wayF.x)
				drawPart("snake_body", body[i].x, body[i].y, 90);
			else if (wayB.y == wayF.y)
				drawPart("snake_body", body[i].x, body[i].y, 0);

			else if (wayF.x > wayB.x && wayF.y < wayB.y && wayF.y == body[i].y)
				drawPart("snake_edge", body[i].x, body[i].y, 0);
			else if (wayF.x < wayB.x && wayF.y > wayB.y && wayF.y == body[i].y)
				drawPart("snake_edge", body[i].x, body[i].y, 180);


			// else if (wayF.x < wayB.x && wayF.y < wayB.y)
				// drawPart("snake_edge", body[i].x, body[i].y, 270);
			// else if (wayF.x > wayB.x && wayF.y < wayB.y)
				// drawPart("snake_edge", body[i].x, body[i].y, 180);
			

			else
				drawPart("background", body[i].x, body[i].y, 0);
		}

		drawPart("snake_tail", body[i].x, body[i].y, getAngle(dir));	
	}

	void	update(void) override
	{
		static unsigned cycle = 0;
		static unsigned wait = 40;
		if (cycle == wait)
		{
			cycle = 0;
			if (dir == 1)
				go_right();
			else if (dir == 2)
				go_left();
			else if (dir == 3)
				go_up();
			else if (dir == 4)
				go_down();
		}
		cycle++;
	}

	void	go_right(void)
	{
		body.pop_back();
		Vector2D p = body.front();
		body.push_front({p.x + Game::cellSize, p.y});
	}

	void	go_up(void)
	{
		body.pop_back();
		Vector2D p = body.front();
		body.push_front({p.x, p.y - Game::cellSize});
	}

	void	go_left(void)
	{
		body.pop_back();
		Vector2D p = body.front();
		body.push_front({p.x - Game::cellSize, p.y});
	}

	void	go_down(void)
	{
		body.pop_back();
		Vector2D p = body.front();
		body.push_front({p.x, p.y + Game::cellSize});
	}
};

#endif