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
#include "NinjaTrap.hpp"

int	main(void)
{
	ClapTrap mama("MAMA");
	FragTrap bot("Mike");
	FragTrap bot2(bot);
	ScavTrap scav("Sam");
	ScavTrap scav1(scav);
	NinjaTrap ninja("Yakohito");

	bot2.set_name("John");
	scav1.set_name("Jimbo");
	std::cout << "-------------------" << std::endl;
	scav.challengeNewcomer();
	bot.vaulthunter_dot_exe("Mouse");
	bot.vaulthunter_dot_exe("Zombie");
	bot.vaulthunter_dot_exe("Goblin");
	bot.vaulthunter_dot_exe("Vampire");
	bot.vaulthunter_dot_exe("Otter");
	ninja.ninjaShoebox(mama.get_name());
	ninja.ninjaShoebox(bot.get_name());
	ninja.ninjaShoebox(scav.get_name());
	ninja.ninjaShoebox(bot2.get_name());
	ninja.ninjaShoebox(scav1.get_name());
	std::cout << "-------------------" << std::endl;
	mama.rangedAttack("Zombie");
	scav.rangedAttack("Zombie");
	bot.rangedAttack("Zombie");
	ninja.rangedAttack("Zombie");
	std::cout << "-------------------" << std::endl;
	mama.meleeAttack("Smoker");
	scav.meleeAttack("Smoker");
	bot.meleeAttack(bot2.get_name());
	ninja.meleeAttack(scav.get_name());
	std::cout << "-------------------" << std::endl;
	mama.takeDamage(30);
	scav.takeDamage(30);
	bot.takeDamage(30);
	ninja.takeDamage(30);
	std::cout << "-------------------" << std::endl;
	std::cout << mama << ": " << mama.get_hit_points() << " hp" << std::endl;
	std::cout << scav << ": " << scav.get_hit_points() << " hp" << std::endl;
	std::cout << bot << ": " << bot.get_hit_points() << " hp" << std::endl;
	std::cout << ninja << ": " << ninja.get_hit_points() << " hp" << std::endl;
	std::cout << "-------------------" << std::endl;
	mama.beRepaired(40);
	scav.beRepaired(20);
	bot2.beRepaired(500);
	ninja.beRepaired(30);
	return (0);
}
