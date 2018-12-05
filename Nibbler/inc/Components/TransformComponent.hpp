// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TransformComponent.hpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/01 17:58:33 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/01 17:58:33 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TRANSFORM_COMPONENT_HPP
# define TRANSFORM_COMPONENT_HPP

# include "Component.hpp"
# include "Framework.hpp"

class TransformComponent: public Component
{
public:
	Vector2D	position;
	int			w;
	int			h;
	double		a;

	TransformComponent(void) : position({0, 0}){}
	TransformComponent(int x, int y, int _w, int _h)
	{
		position.x = x;
		position.y = y;
		w = _w;
		h = _h;
		a = 0;
	}
};

#endif