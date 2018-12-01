// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Map.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/01 17:56:17 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/01 17:56:18 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MAP_HPP
# define MAP_HPP

# include "Game.hpp"

class Map
{
public:
	Map(void){}
	~Map(void){}
	void	loadMap(int lenX, int lenY)
	{
		for (int y = 0; y < lenY; y++)
			for (int x = 0; x < lenX; x++)
			{
				auto &cell(Game::manager.addEntity());
				cell.addComponent<TransformComponent>(x * Game::cellSize, y * Game::cellSize,
													  Game::cellSize, Game::cellSize);
				if (x == 0 || y == 0 || x == lenX - 1 || y == lenY - 1)
				{
					cell.addGroup(group_colliders);
					cell.addComponent<SpriteComponent>("collider");
				}
				else
				{
					cell.addGroup(group_map);
					cell.addComponent<SpriteComponent>("background");
				}
			}
	}
};

#endif