// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Instruction.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/28 20:20:06 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/28 20:20:06 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Instruction.hpp"

Instruction::Instruction(void) : j(0){}

Instruction::~Instruction(void){}

void	Instruction::execute(char ch)
{
	this->j += (ch == '>') ? 1 : 0;
	this->j -= (ch == '<') ? 1 : 0;
	this->mem[j] += (ch == '+') ? 1 : 0;
	this->mem[j] -= (ch == '-') ? 1 : 0;
	if (ch == '.')
		std::cout << mem[j];
	if (ch == ',')
		std::cin >> mem[j];
}

char	&Instruction::operator[](int index)
{
	return (this->mem[index]);
}

unsigned Instruction::getCurrent(void) const
{
	return (this->j);
}
