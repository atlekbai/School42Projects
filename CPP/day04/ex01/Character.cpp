// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 16:06:13 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 16:06:13 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Character.hpp"

Character::Character(std::string const &name) : name(name),
												ap(40),
												weapon(NULL)
{

}

Character::Character(Character const &src)
{
	*this = src;
}

Character::~Character(void)
{
	delete this->weapon;
}

Character	&Character::operator=(Character const &src)
{
	this->name = src.getName();
	this->ap = src.getAp();
	this->weapon = src.getWeapon();
	return (*this);
}

void		Character::recoverAP(void)
{
	if (this->ap + 10 > 40)
		this->ap = 40;
	else
		this->ap += 10;
}

void		Character::equip(AWeapon* weapon)
{
	this->weapon = weapon;
}

void		Character::attack(Enemy* enemy)
{
	AWeapon *wep = this->weapon;
	if (!wep || this->ap < wep->getAPCost())
		return ;
	this->ap -= wep->getAPCost();
	if (enemy->getHP() <= 0)
	{
		std::cout << this->name << " attacked dead " << enemy->getType() << std::endl;
		return ;
	}
	enemy->takeDamage(wep->getDamage());
	std::cout << this->name << " attacks " << enemy->getType() << " with a " << wep->getName() << std::endl;
	if (enemy->getHP() <= 0)
	{
		std::cout << this->name << " killed " << enemy->getType() << std::endl;
		delete enemy;
	}
}

std::string	Character::getName(void) const
{
	return (this->name);
}

int			Character::getAp(void) const
{
	return (this->ap);
}

AWeapon		*Character::getWeapon(void) const
{
	return (this->weapon);
}

std::ostream &operator<<(std::ostream &o, Character const &c)
{
	AWeapon *wep = c.getWeapon();
	o << c.getName() << " has " << c.getAp() << " AP and ";
	if (wep)
		std::cout << "wields a " << wep->getName() << std::endl;
	else
		std::cout << "is unarmed" << std::endl;
	return (o);
}
