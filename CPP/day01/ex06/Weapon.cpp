// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Weapon.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 18:30:56 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/19 19:08:35 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type){}

Weapon::~Weapon(void){}

const std::string	&Weapon::getType(void)
{
	return (this->type);
}

void		Weapon::setType(std::string type)
{
	this->type = type;
}

