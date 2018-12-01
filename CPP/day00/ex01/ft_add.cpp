// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft_add.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/18 17:22:42 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/18 17:22:43 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "header.hpp"

int	set_contact(Contact &contact, int (Contact::*f)(std::string), std::string var)
{
	std::string tmp;

	while ((contact.*f)(tmp) != 1)
	{
		std::cout << "Enter " << var << ": ";
		std::getline(std::cin, tmp);
		(!std::cin) ? exit(0) : (void)NULL;
	}
	return (1);
}

int	ft_add(Contact contacts[], int &i)
{
	if (i >= MAX_CONTACTS)
		std::cout << "PhoneBook is full" << std::endl;
	else
	{
		std::cout << std::endl << "[" << ADD << " COMMAND]" << std::endl << std::endl;
		set_contact(contacts[i], &Contact::setFirstName, "first name");
		set_contact(contacts[i], &Contact::setLastName, "last name");
		set_contact(contacts[i], &Contact::setNickname, "nickname");
		set_contact(contacts[i], &Contact::setLogin, "login");
		set_contact(contacts[i], &Contact::setPostalAddress, "postal address");
		set_contact(contacts[i], &Contact::setEmail, "email address");
		set_contact(contacts[i], &Contact::setPhone, "phone number");
		set_contact(contacts[i], &Contact::setBirth, "birth date");
		set_contact(contacts[i], &Contact::setMeal, "favourite meal");
		set_contact(contacts[i], &Contact::setUndwColor, "underwear color");
		set_contact(contacts[i], &Contact::setSecret, "darkest secret");
		i++;
		std::cout << std::endl << "[" << ADD << " COMMAND FINISHED]" << std::endl << std::endl;
	}
	return (1);
}
