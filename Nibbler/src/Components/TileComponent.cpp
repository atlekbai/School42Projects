// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TileComponent.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/25 22:19:16 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/25 22:19:16 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "TileComponent.hpp"

TileComponent::TileComponent(int x, int y, int src_x, int src_y,
							 int t_size, double t_scale, std::string id)
{
	texture = Game::assets->get_texture(id);
	position.x = x;
	position.y = y;

	src.x = src_x;
	src.y = src_y;
	src.w = t_size;
	src.h = t_size;

	dst.x = x;
	dst.y = y;
	dst.w = t_size * t_scale;
	dst.h = t_size * t_scale;
}

TileComponent::~TileComponent(void)
{}

void TileComponent::update(void)
{
	dst.x = position.x;
	dst.y = position.y;
}

void TileComponent::draw(void)
{
	TextureManager::draw(texture, src, dst, SDL_FLIP_NONE);
}
