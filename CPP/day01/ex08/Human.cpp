// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 20:02:36 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/19 20:28:12 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Human.hpp"

void	Human::action(std::string const & action_name, std::string const & target)
{
	void		(Human::*functions[])(std::string const & target) = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout
	};
	std::string	fun_names[] = {
		"meleeAttack",
		"rangedAttack",
		"intimidatingShout"
	};
	int			i = -1;

	while (++i < 3)
		if (action_name == fun_names[i])
		{
			(this->*(functions[i]))(target);
			break ;
		}
}

void	Human::meleeAttack(std::string const & target)
{
	std::cout << "Melee Attack on " << target << std::endl;
}

void	Human::rangedAttack(std::string const & target)
{
	std::cout << "Ranged Attack on " << target << std::endl;
}

void	Human::intimidatingShout(std::string const & target)
{
	std::cout << "Intimidating Shout on " << target << std::endl;
}
