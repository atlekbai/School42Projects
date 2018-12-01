// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FoodComponent.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/26 16:29:46 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/26 16:29:46 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FOOD_COMPONENT_HPP
# define FOOD_COMPONENT_HPP

# include "Components.hpp"
# include "AssetManager.hpp"
# include "Map.hpp"
# include "stdlib.h"
# include <list>

class FoodComponent: public Component
{
private:
	Vector2D	offset;
	Vector2D	dim;

	SDL_Texture	*texture;
	SDL_Rect	src;
	SDL_Rect	dst;
	
	int			scaled_size;
	bool		eaten = false;

public:
	Vector2D	position;
	FoodComponent(Map *map, std::string id);
	void	init(void) override;
	void	update(void) override;
	void	draw(void) override;
	void	new_position(void);
	void	new_position(std::list<Vector2D> &body);
};

#endif