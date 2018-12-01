// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieHorde.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 16:34:33 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/19 16:34:33 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <cstdlib>
#include <ctime>
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n)
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
    int i = -1;

    srand(time(NULL));
    this->n = n;
    this->horde = new Zombie[n];
    while (++i < n)
        this->horde[i] = Zombie(names[rand() % 7], "Default");
}

ZombieHorde::~ZombieHorde(void)
{
    delete[] (this->horde);
}

void ZombieHorde::announce() const
{
    int i = -1;

    while (++i < this->n)
        this->horde[i].announce();
}
