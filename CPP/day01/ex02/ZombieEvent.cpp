// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieEvent.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 15:09:37 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/19 15:09:37 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void)
{
    this->type = "Default";
    return ;
}

ZombieEvent::~ZombieEvent(void) {}

void    ZombieEvent::setZombieType(std::string type)
{
    this->type = type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
    return (new Zombie(name, this->type));
}

Zombie* ZombieEvent::randomChump(void)
{
    std::string names[] = {
        "Tank",
        "Boomer",
        "Hunter",
        "Smoker",
        "Charger",
        "Jockey",
        "Spitter",
        "Witch",
    };
    srand(time(NULL));
    rand();
    Zombie *z = this->newZombie(names[rand() % 7]);
    z->announce();
    return (z);
}
