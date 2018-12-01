// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Victim.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 13:45:19 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 15:42:56 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Victim.hpp"

Victim::Victim(std::string name) : name(name)
{
	std::cout << "Some random victim called " << name << " just popped !" << std::endl;
}

Victim::~Victim(void)
{
	std::cout << "Victim "<< this->name << " just died for no apparent reason !" << std::endl;
}

Victim::Victim(Victim const &src)
{
	*this = src;
}

Victim			&Victim::operator=(Victim const &src)
{
	this->name = src.getName();
	return (*this);
}

std::string		Victim::getName(void) const
{
	return (this->name);
}

void			Victim::getPolymorphed(void) const
{
	std::cout << this->name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Victim const &v)
{
	o << "I'm " << v.getName() << " and I like otters !" << std::endl;
	return (o);
}
