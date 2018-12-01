// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanA.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 18:30:38 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/19 19:03:39 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name),
												  weapon(weapon){}

HumanA::~HumanA(void){}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with his "
			  << this->weapon.getType() << std::endl;
}
