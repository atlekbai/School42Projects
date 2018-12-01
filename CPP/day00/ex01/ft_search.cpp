// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft_search.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/18 17:22:53 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/18 17:22:53 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "header.hpp"

int	fit_str(std::string &str)
{
	if (str.size() > 10)
	{
		str.resize(10);
		str[9] = '.';
	}
	return (1);
}

int	table_out(std::string index, std::string fn, std::string ln, std::string nn)
{
	fit_str(fn);
	fit_str(ln);
	fit_str(nn);
	std::cout	<< std::setw(TABLE_WIDTH) << std::right << index
				<< "|" << std::setw(TABLE_WIDTH) << std::right << fn
				<< "|" << std::setw(TABLE_WIDTH) << std::right << ln
				<< "|" << std::setw(TABLE_WIDTH) << std::right << nn
				<< std::endl;
	return (0);
}

int	show_contact(Contact contact, int i)
{
	std::cout << std::setw(17) << std::left << std::endl << "Contact №" << i << std::endl;
	std::cout << std::setw(17) << std::left << "-----------------" << std::endl;
	std::cout << std::setw(17) << std::left << "First name: " << contact.getFirstName() << std::endl;
	std::cout << std::setw(17) << std::left << "Last name: " << contact.getLastName() << std::endl;
	std::cout << std::setw(17) << std::left << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << std::setw(17) << std::left << "Login: " << contact.getLogin() << std::endl;
	std::cout << std::setw(17) << std::left << "Postal address: " << contact.getPostalAddress() << std::endl;
	std::cout << std::setw(17) << std::left << "Email address: " << contact.getEmail() << std::endl;
	std::cout << std::setw(17) << std::left << "Phone number: " << contact.getPhone() << std::endl;
	std::cout << std::setw(17) << std::left << "Birth date: " << contact.getBirth() << std::endl;
	std::cout << std::setw(17) << std::left << "Favourite meal: " << contact.getMeal() << std::endl;
	std::cout << std::setw(17) << std::left << "Underwear color: " << contact.getUndwColor() << std::endl;
	std::cout << std::setw(17) << std::left << "Darkest secret: " << contact.getSecret() << std::endl;
	return (1);
}

int	ft_search(Contact contacts[], int i)
{
	int			j = -1;
	int			index;

	std::cout << std::endl << "[" << SEARCH << " COMMAND]" << std::endl << std::endl;
	if (!i)
	{
		std::cout << "PhoneBook is empty, please fill the base" <<std::endl;
		return (0);
	}
	table_out("index", "first name", "last name", "nickname");
	while (++j < i)
		table_out(	std::to_string(j + 1),
					contacts[j].getFirstName(),
					contacts[j].getLastName(),
					contacts[j].getNickname());
	std::cout << "Enter the index of the desired entry: ";
	std::cin >> index;
	std::cin.ignore(256,'\n');
	(!std::cin) ? exit(0) : (void)NULL;
	if ((index > i || index <= 0))
		std::cout << "Error occurred" << std::endl;
	else
		show_contact(contacts[index - 1], index);
	std::cout << std::endl << "[" << SEARCH << " COMMAND FINISHED]" << std::endl << std::endl;
	return (1);
}
