// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Contact.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/18 13:37:34 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/18 13:48:40 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>

class Contact
{
public:
	Contact(void);
	~Contact(void);
	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickname(void) const;
	std::string	getLogin(void) const;
	std::string	getPostalAddress(void) const;
	std::string	getEmail(void) const;
	std::string	getPhone(void) const;
	std::string	getBirth(void) const;
	std::string	getMeal(void) const;
	std::string	getUndwColor(void) const;
	std::string	getSecret(void) const;
	int			setFirstName(std::string first_name);
	int			setLastName(std::string last_name);
	int			setNickname(std::string nickname);
	int			setLogin(std::string login);
	int			setPostalAddress(std::string postal_address);
	int			setEmail(std::string email);
	int			setPhone(std::string phone);
	int			setBirth(std::string birth);
	int			setMeal(std::string meal);
	int			setUndwColor(std::string undw_color);
	int			setSecret(std::string secret);

private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string postal_address;
	std::string email;
	std::string phone;
	std::string birth;
	std::string meal;
	std::string undw_color;
	std::string secret;
};

#endif
