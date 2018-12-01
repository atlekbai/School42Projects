// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 15:09:26 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/19 15:09:26 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) : name(name),
                                                     type(type)
{
    return ;
}

Zombie::~Zombie(void)
{
    return ;
}

void    Zombie::announce(void) const
{
    std::cout   << "<" << this->name << " (" << this->type << ")> Braiiiiiiinnnssss..."
                << std::endl;
}
