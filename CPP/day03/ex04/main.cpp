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
#include "SuperTrap.hpp"

int	main(void)
{
	ClapTrap mama("MAMA");
	FragTrap bot("Mike");
	FragTrap bot2(bot);
	ScavTrap scav("Sam");
	ScavTrap scav1(scav);
	NinjaTrap ninja("Yakohito");
	SuperTrap super("SUPERMAN");

	std::cout << "SuperTrap: " << super << std::endl;
	std::cout << "Hit points: " << super.get_hit_points() << std::endl;
	std::cout << "Max hit points: " << super.get_max_hit_points() << std::endl;
	std::cout << "Energy points: " << super.get_energy_points() << std::endl;
	std::cout << "Max energy points: " << super.get_max_energy_points() << std::endl;
	std::cout << "Level: " << super.get_level() << std::endl;
	std::cout << "Name: " << super.get_name() << std::endl;
	std::cout << "Melee attack damage: " << super.get_melee_attack_damage() << std::endl;
	std::cout << "Ranged attack damage: " << super.get_ranged_attack_damage() << std::endl;
	std::cout << "Armor damage reduction: " << super.get_armor_damage_reduction() << std::endl;


	bot2.set_name("John");
	scav1.set_name("Jimbo");
	std::cout << "-------------------" << std::endl;
	scav.challengeNewcomer();
	bot.vaulthunter_dot_exe("Mouse");
	bot.vaulthunter_dot_exe("Zombie");
	bot.vaulthunter_dot_exe("Goblin");
	bot.vaulthunter_dot_exe("Vampire");
	bot.vaulthunter_dot_exe("Otter");
	ninja.ninjaShoebox(mama);
	ninja.ninjaShoebox(bot);
	ninja.ninjaShoebox(scav);
	ninja.ninjaShoebox(bot2);
	ninja.ninjaShoebox(scav1);
	super.ninjaShoebox("Vampire");
	super.vaulthunter_dot_exe(ninja.get_name());
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
