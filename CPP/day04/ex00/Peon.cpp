// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Peon.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 13:45:29 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 15:55:21 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Peon.hpp"

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const &src) : Victim(src.getName())
{
	*this = src;
}

Peon	&Peon::operator=(Peon const &src)
{
	this->name = src.getName();
	return (*this);
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
}

void	Peon::getPolymorphed(void) const
{
	std::cout << this->getName() << " has been turned into a pink pony !" << std::endl;
}
