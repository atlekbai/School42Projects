// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Contact.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/18 13:52:30 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/18 13:52:31 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Contact.class.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

std::string	Contact::getFirstName(void) const
{
	return (this->first_name);
}

std::string	Contact::getLastName(void) const
{
	return (this->last_name);
}

std::string	Contact::getNickname(void) const
{
	return (this->nickname);
}

std::string	Contact::getLogin(void) const
{
	return (this->login);
}

std::string	Contact::getPostalAddress(void) const
{
	return (this->postal_address);
}

std::string	Contact::getEmail(void) const
{
	return (this->email);
}

std::string	Contact::getPhone(void) const
{
	return (this->phone);
}

std::string	Contact::getBirth(void) const
{
	return (this->birth);
}

std::string	Contact::getMeal(void) const
{
	return (this->meal);
}

std::string	Contact::getUndwColor(void) const
{
	return (this->undw_color);
}

std::string	Contact::getSecret(void) const
{
	return (this->secret);
}

int			Contact::setFirstName(std::string first_name)
{
	if (first_name.empty())
		return (0);
	this->first_name = first_name;
	return (1);
}

int			Contact::setLastName(std::string last_name)
{
	if (last_name.empty())
		return (0);
	this->last_name = last_name;
	return (1);
}

int			Contact::setNickname(std::string nickname)
{
	if (nickname.empty())
		return (0);
	this->nickname = nickname;
	return (1);
}

int			Contact::setLogin(std::string login)
{
	if (login.empty())
		return (0);
	this->login = login;
	return (1);
}

int			Contact::setPostalAddress(std::string postal_address)
{
	if (postal_address.empty())
		return (0);
	this->postal_address = postal_address;
	return (1);
}

int			Contact::setEmail(std::string email)
{
	if (email.empty())
		return (0);
	this->email = email;
	return (1);
}

int			Contact::setPhone(std::string phone)
{
	if (phone.empty())
		return (0);
	this->phone = phone;
	return (1);
}

int			Contact::setBirth(std::string birth)
{
	if (birth.empty())
		return (0);
	this->birth = birth;
	return (1);
}

int			Contact::setMeal(std::string meal)
{
	if (meal.empty())
		return (0);
	this->meal = meal;
	return (1);
}

int			Contact::setUndwColor(std::string undw_color)
{
	if (undw_color.empty())
		return (0);
	this->undw_color = undw_color;
	return (1);
}

int			Contact::setSecret(std::string secret)
{
	if (secret.empty())
		return (0);
	this->secret = secret;
	return (1);
}
