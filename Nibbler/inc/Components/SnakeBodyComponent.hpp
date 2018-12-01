// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SnakeBodyComponent.hpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/25 23:55:33 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/25 23:55:33 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SNAKE_BODY_COMPONENT_HPP
# define SNAKE_BODY_COMPONENT_HPP

# include "Components.hpp"
# include "AssetManager.hpp"
# include "TextureManager.hpp"
# include <list>

/*
	1 - right
	2 - left
	3 - up
	4 - down
*/

class SnakeBodyComponent: public Component
{
public:
	std::list<Vector2D>	body;
	double				scale;
	int					tile_size;
	int					dir = 1;
	int					score = 0;
	
	SDL_Texture			*texture;

	SnakeBodyComponent(std::string id, int len, double scale, int tile_size,
					   int x_start, int y_start);
	void	draw(void) override;
	void	update(void) override;
	void	go_right(void);
	void	go_up(void);
	void	go_left(void);
	void	go_down(void);
	void	add_tail(void);
	bool	collide(const Vector2D &pos);
};

#endif