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

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap mama("MAMA");
	FragTrap bot("Mike");
	FragTrap bot2(bot);
	ScavTrap scav("Sam");
	ScavTrap scav1(scav);

	mama.takeDamage(30);
	mama.beRepaired(40);
	bot2.set_name("John");
	scav1.set_name("Jimbo");
	scav.rangedAttack("Bird");
	scav.meleeAttack("Smoker");
	scav.beRepaired(20);
	scav.takeDamage(1);
	scav.challengeNewcomer();
	bot.rangedAttack("Zombie");
	bot.meleeAttack(bot2.get_name());
	bot2.beRepaired(500);
	bot.takeDamage(10);
	bot.vaulthunter_dot_exe("Mouse");
	bot.vaulthunter_dot_exe("Zombie");
	bot.vaulthunter_dot_exe("Goblin");
	bot.vaulthunter_dot_exe("Vampire");
	bot.vaulthunter_dot_exe("Otter");

	return (0);
}
