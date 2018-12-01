// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/21 12:58:37 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/21 12:58:37 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap bot("Mike");
	FragTrap bot2(bot);

	bot2.set_name("John");
	std::cout << "ClapBot: " << bot << std::endl;
	std::cout << "ClapBot: " << bot2 << std::endl;
	bot.rangedAttack("Zombie");
	bot.meleeAttack(bot2.get_name());
	bot2.beRepaired(500);
	bot.takeDamage(10);
	bot.vaulthunter_dot_exe("Mouse");
	bot.vaulthunter_dot_exe("Mouse");
	bot.vaulthunter_dot_exe("Mouse");
	bot.vaulthunter_dot_exe("Mouse");
	bot.vaulthunter_dot_exe("Mouse");
	bot.vaulthunter_dot_exe("Mouse");
	return (0);
}
