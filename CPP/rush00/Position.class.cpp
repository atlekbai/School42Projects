// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Position.class.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 21:23:31 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/23 21:23:32 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Position.class.hpp"

Position & Position::operator=(Position const & rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;	
	return *this;
}

bool Position::operator==(Position const & rhs) const
{
	if (this->x == rhs.x && this->y == rhs.y)
		return true;
	return false;
}

Position::Position(const Position & toCopy): x(toCopy.x), y(toCopy.y){}
Position::Position(int x, int y): x(x), y(y){}
Position::Position(void): x(0), y(0){}
Position::~Position(void){}

std::ostream & operator<<(std::ostream & o, Position const & rhs)
{
	o << "(y[" << rhs.y << "], x[" << rhs.x << "])";
	return o;
}
