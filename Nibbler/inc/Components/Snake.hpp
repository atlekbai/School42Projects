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

class Snake: public Component
{
public:
	int						dir;
	unsigned 				cycle;
	std::deque<Vector2D>	body;
	Snake(int x, int y, int length)
	{
		for (int i = 0; i < length; i++)
			body.push_back({(x - i) * Game::cellSize, y * Game::cellSize});
		dir = 1;
		cycle = 0;
	}
	void	draw(void) override;

	void	update(void) override;
	void	go_right(void);
	void	go_up(void);
	void	go_left(void);
	void	go_down(void);
	void	setDir(int newDir);
	void	addTail(void);
};

#endif