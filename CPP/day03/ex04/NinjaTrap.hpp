// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NinjaTrap.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/21 18:07:35 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/21 18:31:24 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap: virtual public ClapTrap
{
public:
	NinjaTrap(void);
	NinjaTrap(std::string name);
	NinjaTrap(NinjaTrap const &src);
	~NinjaTrap(void);
	NinjaTrap	&operator=(NinjaTrap const &src);
	int			ninjaShoebox(std::string const &target);
	int			ninjaShoebox(ClapTrap const &target);
	int			ninjaShoebox(FragTrap const &target);
	int			ninjaShoebox(ScavTrap const &target);
};

std::ostream &operator<<(std::ostream &o, NinjaTrap const &n);

#endif
