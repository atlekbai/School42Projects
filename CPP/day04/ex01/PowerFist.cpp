// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PowerFist.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 16:06:40 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 16:06:41 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50){}

PowerFist::PowerFist(PowerFist const &src): AWeapon("Plasma Rifle", 5, 21)
{
	*this = src;
}

PowerFist::~PowerFist(void){}

PowerFist &PowerFist::operator=(PowerFist const &src)
{
	this->setName(src.getName());
	this->setAPCost(src.getAPCost());
	this->setDamage(src.getDamage());
	return (*this);
}

void		PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
