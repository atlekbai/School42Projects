// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/21 12:58:31 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/21 12:58:32 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : public ClapTrap 
{
public:
	FragTrap(std::string name);
	FragTrap(FragTrap const &src);
	~FragTrap(void);
	FragTrap	&operator=(FragTrap const &rhs);

	int			vaulthunter_dot_exe(std::string const & target);
	int			Clap_In_The_Box(std::string const & target);
	int			Torgue_Fiesta(std::string const & target);
	int			One_Shot_Wonder(std::string const & target);
	int			Laser_Inferno(std::string const & target);
	int			Meat_Unicycle(std::string const & target);
};

std::ostream &operator<<(std::ostream &o, FragTrap const &f);

#endif