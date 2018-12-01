// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ice.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 20:22:30 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 20:22:30 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice"){}

Ice::Ice(Ice const &src)
{
	*this = src;
}

Ice::~Ice(void){}

Ice 				&Ice::operator=(Ice const &src)
{
	this->setType(src.getType());
	this->setXP(src.getXP());
	return (*this);
}

Ice					*Ice::clone(void) const
{
	return (new Ice());
}

void				Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	this->setXP(this->getXP() + 1);
}
