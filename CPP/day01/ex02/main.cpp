// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 15:09:45 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/19 15:09:45 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "ZombieEvent.hpp"

int check(void)
{
    Zombie zombie = Zombie("Markus", "Weak");
    ZombieEvent zombie_event = ZombieEvent();
    Zombie *zombie_heap1 = zombie_event.newZombie("John");
    zombie_event.setZombieType("Dangerous");
    Zombie *zombie_heap2 = zombie_event.newZombie("Alex");
    Zombie *zombie_heap3 = zombie_event.randomChump();

    zombie.announce();
    zombie_heap1->announce();
    zombie_heap2->announce();
    delete zombie_heap1;
    delete zombie_heap2;
    delete zombie_heap3;
    return (1);
}
int main()
{
    check();
    return (0);
}