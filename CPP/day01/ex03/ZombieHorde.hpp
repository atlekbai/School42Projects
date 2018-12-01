// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieHorde.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 16:34:36 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/19 16:34:37 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include <iostream>
#include "Zombie.hpp"

class   ZombieHorde
{
public:
    ZombieHorde(int n);
    ~ZombieHorde();
    void    announce(void) const;

private:
    Zombie  *horde;
    int     n;
};

#endif