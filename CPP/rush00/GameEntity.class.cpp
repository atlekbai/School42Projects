// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameEntity.class.cpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 21:24:06 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/23 21:24:06 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GameEntity.class.hpp"

bool GameEntity::isCollidingWith(const GameEntity & entity) const
{
	return this->pos == entity.pos;
}

bool GameEntity::isDead(void) const
{
	return this->_hp == 0;
}

int GameEntity::getHP(void) const
{
	return this->_hp;
}

int GameEntity::getSpeed(void) const
{
	return this->_movingSpeed;
}

char GameEntity::getDispChar(void) const
{
	return (this->_disp_char);
}

Rect	GameEntity::getRect(void) const
{
	return this->_end;
}

void GameEntity::setHP(int amount)
{
	this->_hp = amount;
}

void	GameEntity::setRect(Rect rec)
{
	this->_end = rec;
}

void GameEntity::takeDamage(int amount)
{
	this->_hp -= amount;
	if (this->_hp < 0) {
		this->_hp = 0;
	}
}

GameEntity & GameEntity::operator=(GameEntity const & rhs)
{
	this->_hp = rhs._hp;
	this->_movingSpeed = rhs._movingSpeed;
	this->pos = rhs.pos;

	return *this;
}

GameEntity::GameEntity(const GameEntity& toCopy): _hp(toCopy._hp),
												_movingSpeed(toCopy._movingSpeed)
{
	this->pos = toCopy.pos;
}

GameEntity::GameEntity(char disp_char,
						Position pos,
						Rect _end,
						int hp,
						int movingSpeed):	_disp_char(disp_char),
											_end(_end),
											_hp(hp),
											_movingSpeed(movingSpeed),
											pos(pos){}

GameEntity::GameEntity(void):	_end(Rect(0, 0, 0, 0)),
								_hp(1),
								_movingSpeed(1),
								pos(Position()){}

GameEntity::~GameEntity(void) {}
