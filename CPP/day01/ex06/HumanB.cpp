// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanB.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 18:30:38 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/19 19:04:01 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(0){}

HumanB::~HumanB(void){}

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with his "
			  << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
