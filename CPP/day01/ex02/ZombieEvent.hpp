// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieEvent.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 15:09:40 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/19 15:09:41 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

# include <iostream>
# include "Zombie.hpp"

class ZombieEvent
{
public:
    ZombieEvent(void);
    ~ZombieEvent(void);
    void    setZombieType(std::string type);
    Zombie* newZombie(std::string name);
    Zombie* randomChump(void);

private:
    std::string type;
};

#endif