// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cure.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 20:22:43 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 20:22:43 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure"){}

Cure::Cure(Cure const &src)
{
	*this = src;
}

Cure::~Cure(void){}

Cure 				&Cure::operator=(Cure const &src)
{
	this->setType(src.getType());
	this->setXP(src.getXP());
	return (*this);
}

Cure					*Cure::clone(void) const
{
	return (new Cure());
}

void				Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	this->setXP(this->getXP() + 1);
}
