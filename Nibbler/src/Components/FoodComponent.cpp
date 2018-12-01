// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FoodComponent.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/26 16:29:36 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/26 16:29:37 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FoodComponent.hpp"
#include <vector>

FoodComponent::FoodComponent(Map *map, std::string id)
{
	offset.x = map->offset.x;
	offset.y = map->offset.y;
	dim.x = map->dim.x;
	dim.y = map->dim.y;
	
	scaled_size = map->scaled_size;
	texture = Game::assets->get_texture(id);

	src = {0, 0, scaled_size * 2, scaled_size * 2};
	dst = {0, 0, scaled_size, scaled_size};
}

void	FoodComponent::init(void)
{
	new_position();
}

void	FoodComponent::update(void)
{
	if (eaten)
		new_position();

	dst.x = position.x * scaled_size;
	dst.y = position.y * scaled_size;
}

void	FoodComponent::draw(void)
{
	TextureManager::draw(texture, src, dst, SDL_FLIP_NONE);
}

void	FoodComponent::new_position(void)
{
	srand(time(NULL));
	int x = (rand() % ((int)dim.x - 2 - (int)offset.x)) + offset.x + 1;
	int y = (rand() % ((int)dim.y - 2 - (int)offset.y)) + offset.y + 1;
	position.x = x;
	position.y = y;
}

void	FoodComponent::new_position(std::list<Vector2D> &body)
{
	std::vector<Vector2D> free_spaces;
	bool				busy;
	int					x;
	int					y;
	for (y = offset.y + 1; y < (int)dim.y - 2 + (int)offset.y; y++)
		for (x = offset.x + 1; x < (int)dim.x - 2 + (int)offset.x; x++)
		{
			busy = false;
			for (auto b: body)
				if (x == b.x && y == b.y)
					busy = true;
			if (!busy)
				free_spaces.push_back(Vector2D(x, y));
		}
	int i = rand() % free_spaces.size();
	position.x = free_spaces[i].x;
	position.y = free_spaces[i].y;

}