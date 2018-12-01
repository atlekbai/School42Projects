// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sorcerer.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 13:45:07 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 15:46:23 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : name(name),
														 title(title)
{
	std::cout << name << ", " << title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &src)
{
	*this = src;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->name << ", " << this->title << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer		&Sorcerer::operator=(Sorcerer const &src)
{
	this->name = src.getName();
	this->title = src.getTitle();
	return (*this);
}

std::string		Sorcerer::getName(void) const
{
	return (this->name);
}

std::string		Sorcerer::getTitle(void) const
{
	return (this->title);
}

void			Sorcerer::polymorph(Victim const &v) const
{
	v.getPolymorphed();
}

std::ostream	&operator<<(std::ostream &o, Sorcerer const &s)
{
    o << "I am " << s.getName() << ", " << s.getTitle() << ", and I like ponies !" << std::endl;
    return (o);
}
