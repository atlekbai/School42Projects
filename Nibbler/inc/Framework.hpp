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
# include <map>

class Entity;

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

enum	event
{
	empty,
	
	right1,
	left1,
	up1,
	down1,

	right2,
	left2,
	up2,
	down2,

	space,
	escape,

	menu1,
	menu2,
	menu3,
	menu4,
	menu5,

	frame1,
	frame2,
	frame3,
	exit_event
};
class Framework
{
public:
	bool				is_ready = false;

	virtual void		init(const char *title, int width, int height, std::map<std::string, std::string> menu) = 0;
	virtual void		close(void) = 0;
	virtual void		draw(std::string textureId, Rect src, Rect dst, double angle) = 0;
	virtual void		clear(void) = 0;
	virtual void		render(void) = 0;
	virtual int			handleEvents(std::vector<Entity*> ui) = 0;
	virtual unsigned	ticks(void) = 0;
	virtual void		delay(int time) = 0;
	virtual void		drawScore(int score, int id, int x, int y) = 0;
	virtual void		loadAssets(std::map<std::string, std::string> menu) = 0;


	virtual ~Framework(void){}
};

#endif