// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/25 14:03:35 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/25 14:03:35 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <fstream>
#include "Components.hpp"
#include "Map.hpp"

extern Manager manager;

Map::Map(double scl, int tl_size)
{
	scale = scl;
	tile_size = tl_size;
	scaled_size = scale * tile_size;
	space_id = "dirt";
	block_id = "stone";
}

Map::~Map(void)
{}

void	Map::load_map(int size_x, int size_y, int w_off, int h_off)
{
	/*
		1. Read map loop : yes
		2. End reading obstacle map : yes
	*/

	char			c;
	int				dst_x;
	int				dst_y;
	dim.x = size_x;
	dim.y = size_y;
	offset.x = w_off;
	offset.y = h_off;

	for (int y = 0; y < size_y; y++)
		for (int x = 0; x < size_x; x++)
		{
			dst_x = (x + offset.x) * scaled_size;
			dst_y = (y + offset.y) * scaled_size;
			add_tile(space_id, 0, 0, dst_x, dst_y);
			if (y == 0 || x == 0 || y == size_y - 1 || x == size_x - 1)
				add_tile(block_id, 0, 0, dst_x, dst_y);
		}
}

void	Map::add_tile(std::string id, int src_x, int src_y, int x, int y)
{
	auto &tile(manager.add_entity());
	tile.add_component<TileComponent>(x, y, src_x, src_y, tile_size, scale, id);
	tile.add_group(Game::group_map);
}
