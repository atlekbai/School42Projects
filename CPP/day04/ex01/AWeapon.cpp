// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AWeapon.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 16:06:06 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 16:06:06 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int apcost, int damage) : name(name),
																	apcost(apcost),
																	damage(damage){}

AWeapon::AWeapon(AWeapon const &src)
{
	*this = src;
}

AWeapon::~AWeapon(){}

AWeapon &AWeapon::operator=(AWeapon const &src)
{
	this->name = src.getName();
	this->apcost = src.getAPCost();
	this->damage = src.getDamage();
	return (*this);
}


std::string			AWeapon::getName(void) const
{
	return (this->name);
}

int					AWeapon::getAPCost(void) const
{
	return (this->apcost);
}

int					AWeapon::getDamage(void) const
{
	return (this->damage);
}

int					AWeapon::setName(std::string name)
{
	this->name = name;
	return (1);
}

int					AWeapon::setAPCost(int apcost)
{
	this->apcost = apcost;
	return (1);
}

int					AWeapon::setDamage(int damage)
{
	this->damage = damage;
	return (1);
}
