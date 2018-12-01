// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/21 12:58:31 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/21 12:58:32 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &src);
	~ScavTrap(void);
	ScavTrap	&operator=(ScavTrap const &rhs);

	int			challengeNewcomer(void);
	int			water_bucket(void);
	int			party_night(void);
	int			throw_cake(void);
	int			take_photo(void);
	int			give_hug(void);
};

std::ostream &operator<<(std::ostream &o, ScavTrap const &f);

#endif