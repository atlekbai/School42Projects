// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 20:23:02 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 20:23:02 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Character.hpp"

Character::Character(std::string name) : name(name)
{
	this->inventory = new AMateria*[4];
	this->inventory[0] = NULL;
	this->inventory[1] = NULL;
	this->inventory[2] = NULL;
	this->inventory[3] = NULL;
}

Character::Character(Character const &src)
{
	delete (this->inventory);
	*this = src;
}

Character::~Character(void)
{
	delete (this->inventory);
}

Character 			&Character::operator=(Character const &src)
{
	delete (this->inventory);
	this->name = src.getName();
	this->inventory = src.getInventory();
	return (*this);
}

std::string const	&Character::getName() const
{
	return (this->name);
}

void 				Character::equip(AMateria* m)
{
	int i = -1;

	while (++i < 4)
		if (this->inventory[i] == NULL)
			break ;
	if (i == 4)
		return ;
	this->inventory[i] = m;
}

void 				Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	this->inventory[idx] = NULL;
}

void 				Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || this->inventory[idx] == NULL)
		return ;
	this->inventory[idx]->use(target);
}

AMateria			**Character::getInventory(void) const
{
	return (this->inventory);
}