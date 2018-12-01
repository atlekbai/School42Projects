// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PlasmaRifle.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 16:06:32 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 16:06:33 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21){}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src): AWeapon("Plasma Rifle", 5, 21)
{
	*this = src;
}

PlasmaRifle::~PlasmaRifle(void){}

PlasmaRifle &PlasmaRifle::operator=(PlasmaRifle const &src)
{
	this->setName(src.getName());
	this->setAPCost(src.getAPCost());
	this->setDamage(src.getDamage());
	return (*this);
}

void		PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
