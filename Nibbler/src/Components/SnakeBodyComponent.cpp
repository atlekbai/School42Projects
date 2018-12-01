// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SnakeBodyComponent.cpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/25 23:55:40 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/25 23:55:40 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SnakeBodyComponent.hpp"

SnakeBodyComponent::SnakeBodyComponent(std::string id, int len,
									   double scl, int tl_size,
									   int x_start, int y_start)
{
	scale = scl;
	tile_size = tl_size;
	texture = Game::assets->get_texture(id);
    for (int i = 0; i < len; i++)
        body.push_back(Vector2D(x_start - i, y_start));
}

void	SnakeBodyComponent::draw(void)
{
	SDL_Rect src = {0, 0, 32, 32};
	SDL_Rect dst;
	for (auto p: body)
	{
		dst.x = p.x * scale * tile_size;
		dst.y = p.y * scale * tile_size;
		dst.w = tile_size * scale;
		dst.h = tile_size * scale;
		TextureManager::draw(texture, src, dst, SDL_FLIP_NONE);
	}
}

void	SnakeBodyComponent::update(void)
{
	static unsigned cycle = 0;
	static unsigned wait = 10;
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

void	SnakeBodyComponent::go_right(void)
{
	body.pop_back();
	Vector2D p = body.front();
	body.push_front(Vector2D(p.x + 1, p.y));
}

void	SnakeBodyComponent::go_up(void)
{
	body.pop_back();
	Vector2D p = body.front();
	body.push_front(Vector2D(p.x, p.y - 1));
}

void	SnakeBodyComponent::go_left(void)
{
	body.pop_back();
	Vector2D p = body.front();
	body.push_front(Vector2D(p.x - 1, p.y));
}

void	SnakeBodyComponent::go_down(void)
{
	body.pop_back();
	Vector2D p = body.front();
	body.push_front(Vector2D(p.x, p.y + 1));
}

void	SnakeBodyComponent::add_tail(void)
{
	Vector2D back = body.back();
	Vector2D pen = *++body.rbegin();
	Vector2D direction = Vector2D::diff(back, pen);
	if (direction.x == 1 && direction.x == 0)
		back.x -= 1;
	else if (direction.x == -1 && direction.x == 0)
		back.x += 1;
	else if (direction.x == 0 && direction.x == 1)
		back.y += 1;
	else if (direction.x == 0 && direction.x == -1)
		back.y -= 1;
	score++;
	body.push_back(back);
}

bool	SnakeBodyComponent::collide(const Vector2D &pos)
{
	for (auto b: body)
	{
		if (b.x == pos.x && b.y == pos.y)
			return (true);
	}
	return (false);
}