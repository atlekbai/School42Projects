// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Factory.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/09 14:33:08 by atlekbai          #+#    #+#             //
//   Updated: 2018/07/09 14:33:09 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Factory.class.hpp"
#include "Operand.class.hpp"
#include <climits>

IOperand const	*Factory::createInt8	(std::string const &value) const
{
	if (std::stoi(value) < CHAR_MIN || std::stoi(value) > CHAR_MAX)
		throw std::out_of_range("Error: out of range");
	return (new Operand<char>(static_cast<char>(std::stoi(value))));
}

IOperand const	*Factory::createInt16	(std::string const &value) const
{
	if (std::stoi(value) < SHRT_MIN || std::stoi(value) > SHRT_MAX)
		throw std::out_of_range("Error: out of range");
	return (new Operand<short int>(static_cast<short int>(std::stoi(value))));
}

IOperand const	*Factory::createInt32	(std::string const &value) const
{
	return (new Operand<int>(std::stoi(value)));
}

IOperand const	*Factory::createFloat	(std::string const &value) const
{
	return (new Operand<float>(std::stof(value)));
}

IOperand const	*Factory::createDouble	(std::string const &value) const
{
	return (new Operand<double>(std::stod(value)));
}

IOperand const	*Factory::createOperand	(eOperandType type,
										 std::string const &value) const
{
	IOperand const	*(Factory::*method[])(std::string const &value) const = {
		&Factory::createInt8,
		&Factory::createInt16,
		&Factory::createInt32,
		&Factory::createFloat,
		&Factory::createDouble
	};
	return ((this->*method[type])(value));
}