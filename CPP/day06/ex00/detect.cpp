// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   detect.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/26 15:52:37 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/26 15:52:37 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "main.hpp"

bool	isDouble(std::string s)
{
	int dot = 0;

	if (s == "nan" || s == "-inf" || s == "+inf" )
		return (true);
	if (s[0] != '-' && !(std::isdigit(s[0])))
		return (false);
	for (size_t i = 1; i < s.size(); i++)
	{
		if (!(std::isdigit(s[i]) || s[i] == '.') && dot > 1)
			return (false);
		dot += (s[i] == '.') ? 1 : 0;
	}
	return (true);
}

bool	isFloat(std::string s)
{
	int dot = 0;

	if (s == "nanf" || s == "-inff" || s == "+inff" )
		return (true);
	if (s[0] != '-' && !(std::isdigit(s[0])))
		return (false);
	for (size_t i = 1; i < s.size() - 1; i++)
	{
		if (!(std::isdigit(s[i]) || s[i] == '.') && dot > 1)
			return (false);
		dot += (s[i] == '.') ? 1 : 0;
	}
	if (s.at(s.size() - 1) == 'f')
		return (true);
	return (false);
}

bool	isInt(std::string s)
{
	if (s[0] != '-' && !(std::isdigit(s[0])))
		return (false);
	for (size_t i = 1; i < s.size(); i++)
		if (!std::isdigit(s[i]))
			return (false);
	return (true);
}

bool	isChar(std::string s)
{
	if (s.size() == 1)
		return (true);
	return (false);
}
