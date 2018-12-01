// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/21 12:58:22 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/21 12:58:23 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ScavTrap.hpp"
#include <ctime>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->max_hit_points = 100;
	this->energy_points = 50;
	this->max_energy_points = 50;
	this->level = 1;
	this->melee_attack_damage = 20;
	this->ranged_attack_damage = 15;
	this->armor_damage_reduction = 3;
	std::cout << "ScavTrap " << name << " created." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src.get_name())
{
	*this = src;
	std::cout << "ScavTrap " << this->name << " copied." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->name << " destroyed." << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)
{
	this->hit_points = rhs.get_hit_points();
	this->max_hit_points = rhs.get_max_hit_points();
	this->energy_points = rhs.get_energy_points();
	this->max_energy_points = rhs.get_max_energy_points();
	this->level = rhs.get_level();
	this->name = rhs.get_name();
	this->melee_attack_damage = rhs.get_melee_attack_damage();
	this->ranged_attack_damage = rhs.get_ranged_attack_damage();
	this->armor_damage_reduction = rhs.get_armor_damage_reduction();
	return (*this);
}

int			ScavTrap::water_bucket(void)
{
	std::cout << this->name << " poured a water bucket on newcomer" << std::endl;
	return (1);
}

int			ScavTrap::party_night(void)
{
	std::cout << this->name << " invited a newcomer to party" << std::endl;
	return (1);
}

int			ScavTrap::throw_cake(void)
{
	std::cout << this->name << " threw cake into face of newcomer" << std::endl;
	return (1);
}

int			ScavTrap::take_photo(void)
{
	std::cout << this->name << " took a photo of a newcomer" << std::endl;
	return (1);
}

int			ScavTrap::give_hug(void)
{
	std::cout << this->name << " gave a hug to newcomer" << std::endl;
	return (1);
}

int			ScavTrap::challengeNewcomer(void)
{
	int		(ScavTrap::*challenges[])(void) = {
		&ScavTrap::water_bucket,
		&ScavTrap::party_night,
		&ScavTrap::throw_cake,
		&ScavTrap::take_photo,
		&ScavTrap::give_hug
	};
	srand(time(NULL));
	(this->*(challenges[rand() % 4]))();
	return (1);
}

std::ostream	&operator<<(std::ostream &o, ScavTrap const &f)
{
	o << f.get_name();
	return (o);
}
