// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 16:06:22 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 16:06:23 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Enemy.hpp"

Enemy::Enemy(int hp, std::string const &type) : hp(hp), type(type){}
Enemy::Enemy(Enemy const &src)
{
	*this = src;
}
Enemy::~Enemy(void){}
Enemy			&Enemy::operator=(Enemy const &src)
{
	this->hp = src.getHP();
	this->type = src.getType();
	return (*this);
}

std::string		Enemy::getType(void) const
{
	return (this->type);
}

int				Enemy::getHP(void) const
{
	return (this->hp);
}

int				Enemy::setType(std::string type)
{
	this->type = type;
	return (1);
}

int				Enemy::setHP(int hp)
{
	this->hp = hp;
	return (1);
}

void			Enemy::takeDamage(int damage)
{
	if (damage < 0)
		return ;
	else if (damage > this->hp)
		this->hp = 0;
	else
		this->hp -= damage;
}
