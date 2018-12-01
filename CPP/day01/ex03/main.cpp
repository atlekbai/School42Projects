// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 16:34:40 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/21 12:20:53 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "ZombieHorde.hpp"

int check2(void)
{
    ZombieHorde *z = new ZombieHorde(50);
    std::cout << "--- Check Zombie Horde on Heap ---" << std::endl;
    z->announce();
    delete z;
    return (1);
}

int check1(void)
{
    ZombieHorde z = ZombieHorde(50);
    std::cout << "--- Check Zombie Horde on Stack ---" << std::endl;
    z.announce();
    return (0);
}

int main(void)
{
    check1();
    check2();
    return (1);
}
