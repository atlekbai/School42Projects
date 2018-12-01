// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 17:06:04 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/19 17:25:11 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Human.hpp"

Human::Human(void){}

Human::~Human(void){}

Brain		Human::getBrain(void) const
{
	return (this->brain);
}

std::string	Human::identify(void) const
{
	return (this->brain.identify());
}
