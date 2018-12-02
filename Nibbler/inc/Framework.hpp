// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Framework.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/01 16:40:27 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/01 16:40:27 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FRAMEWORK_HPP
# define FRAMEWORK_HPP

# include <iostream>

struct	Rect
{
	int x;
	int y;
	int w;
	int h;
};

struct	Vector2D
{
	int x;
	int y;
};

enum	group
{
	group_map,
	group_player,
	group_food,
	group_colliders,
	group_ui
};

class Framework
{
public:
	bool				is_ready = false;

	virtual void		init(const char *title, int width, int height) = 0;
	virtual void		close(void) = 0;
	virtual void		draw(std::string textureId, Rect src, Rect dst, double angle) = 0;
	virtual void		clear(void) = 0;
	virtual void		render(void) = 0;
	virtual int			handleEvents(void) = 0;
	virtual unsigned	ticks(void) = 0;
	virtual void		delay(int time) = 0;
	virtual ~Framework(void){}
};

#endif