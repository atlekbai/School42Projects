// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperTrap.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/21 19:03:00 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/21 19:03:00 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap: public FragTrap, public NinjaTrap
{
public:
    SuperTrap(std::string name);
    SuperTrap(SuperTrap const &src);
    ~SuperTrap(void);
    SuperTrap   &operator=(SuperTrap const &src);
};

std::ostream &operator<<(std::ostream &o, SuperTrap const &f);

#endif