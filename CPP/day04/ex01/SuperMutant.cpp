// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperMutant.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 16:07:21 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 16:07:21 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &src) : Enemy(170, "Super Mutant")
{
	*this = src;
}

SuperMutant::~SuperMutant(void)
{
	std::cout << "Aaargh ..." << std::endl;
}

SuperMutant	&SuperMutant::operator=(SuperMutant const &src)
{
	this->setHP(src.getHP());
	this->setType(src.getType());
	return (*this);
}

void		SuperMutant::takeDamage(int n)
{
	if (n < 0)
		return ;
	else if (n >= 3)
		n -= 3;
	else if (n < 3)
		n = 0;
	if (n > this->getHP())
		this->setHP(0);
	else
		this->setHP(this->getHP() - n);
}