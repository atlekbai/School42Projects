// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 15:09:29 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/19 15:09:30 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
public:
    Zombie(std::string name, std::string type);
    ~Zombie(void);
    void    announce(void) const;

private:
    std::string name;
    std::string type;
};

#endif