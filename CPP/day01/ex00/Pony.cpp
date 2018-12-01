// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pony.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 14:19:03 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/19 14:19:04 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Pony.hpp"

Pony::Pony(void)
{
	std::cout << "Pony created" << std::endl;
	return ;
}

Pony::~Pony(void)
{
	std::cout << "Pony " << this->getName() << " terminated" << std::endl;
	return ;
}

std::string	Pony::getName(void) const
{
	return (this->name);
}

std::string	Pony::getColor(void) const
{
	return (this->color);
}

unsigned	Pony::getAge(void) const
{
	return (this->age);
}

int			Pony::getCornLength(void) const
{
	return (this->corn_length);
}

int			Pony::setName(std::string name)
{
	if (name.empty())
		return (0);
	this->name = name;
	return (1);
}

int			Pony::setColor(std::string color)
{
	if (name.empty())
		return (0);
	this->color = color;
	return (1);
}

int			Pony::setAge(unsigned age)
{
	this->age = age;
	return (1);
}

int			Pony::setCornLength(int corn_length)
{
	this->corn_length = corn_length;
	return (1);
}
