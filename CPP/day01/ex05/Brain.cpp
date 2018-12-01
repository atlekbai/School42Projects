// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Brain.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 17:05:55 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/19 17:26:10 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Brain.hpp"

Brain::Brain(void)
{
	std::stringstream mem;

	mem << this;
	this->address = mem.str();
}

Brain::~Brain(void){}

std::string	Brain::identify(void) const
{
	return (this->address);
}
