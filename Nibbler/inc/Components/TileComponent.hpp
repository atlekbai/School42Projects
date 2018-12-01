// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TileComponent.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/25 22:19:08 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/25 22:19:09 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TILE_COMPONENT_HPP
# define TILE_COMPONENT_HPP

# include "Components.hpp"
# include "Vector2D.hpp"
# include "SDL2/SDL.h"

class TileComponent: public Component
{
public:
	SDL_Texture	*texture;
	Vector2D	position;
	SDL_Rect	src;
	SDL_Rect	dst;
	TileComponent(int x, int y, int src_x, int src_y,
				  int t_size, double t_scale, std::string id);
	~TileComponent(void);
	void update(void) override;
	void draw(void) override;
};

#endif