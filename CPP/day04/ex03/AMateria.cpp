// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AMateria.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 20:22:24 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 20:22:24 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AMateria.hpp"

AMateria::AMateria(void) : xp_(0){}

AMateria::AMateria(std::string const &type) :	type(type),
												xp_(0){}
AMateria::AMateria(AMateria const &src)
{
	*this = src;
}

AMateria::~AMateria(void){}

AMateria &AMateria::operator=(AMateria const &src)
{
	this->type = src.getType();
	this->xp_ = src.getXP();
	return (*this);
}

std::string	const	&AMateria::getType(void) const
{
	return (this->type);
}

unsigned int		AMateria::getXP(void) const
{
	return (this->xp_);
}

int					AMateria::setXP(unsigned int xp)
{
	this->xp_ = xp;
	return (1);
}

int					AMateria::setType(std::string type)
{
	this->type = type;
	return (1);
}

