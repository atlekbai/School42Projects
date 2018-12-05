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

# include "Component.hpp"
# include "Framework.hpp"
# include <deque>
# include <map>

class Snake: public Component
{
private:
	int d1;
	int d2;
	int d3;
	int d4;
	std::map<int, void(Snake::*)()> controller;
	int		getAngle(int dir);
	
public:
	int						dir;
	unsigned 				cycle;
	std::deque<Vector2D>	body;
	int 					id;
	int						score;

	Snake(int x, int y, int length, int i, int c1, int c2, int c3, int c4);
	void	draw(void) override;

	void	update(void) override;
	void	go_right(void);
	void	go_up(void);
	void	go_left(void);
	void	go_down(void);
	void	setDir(int newDir);
	void	addTail(void);
	void	cut(int i);
};

#endif