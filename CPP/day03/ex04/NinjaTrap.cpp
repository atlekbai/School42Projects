// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NinjaTrap.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/21 18:07:32 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/21 18:49:15 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) : ClapTrap()
{
	this->hit_points = 60;
	this->max_hit_points = 60;
	this->energy_points = 120;
	this->max_energy_points = 120;
	this->level = 1;
	this->melee_attack_damage = 60;
	this->ranged_attack_damage = 5;
	this->armor_damage_reduction = 0;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 60;
	this->max_hit_points = 60;
	this->energy_points = 120;
	this->max_energy_points = 120;
	this->level = 1;
	this->melee_attack_damage = 60;
	this->ranged_attack_damage = 5;
	this->armor_damage_reduction = 0;
	std::cout << "NinjaTrap " << name << " was created" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src) : ClapTrap(src.get_name())
{
	*this = src;
	std::cout << "NinjaTrap " << this->name << " was copied" << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "NinjaTrap " << this->name << " destroyed" << std::endl;
}

NinjaTrap	&NinjaTrap::operator=(NinjaTrap const &rhs)
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

int			NinjaTrap::ninjaShoebox(std::string const &target)
{
	if (this->energy_points >= 25)
	{
		this->energy_points -= 25;
		std::cout << "NinjaTrap " << this->name << " threw his shoe on " << target << std::endl;
	}
	else
		std::cout << "NinjaTrap " << this->name << " doesn't have enough energy to execute his superpower!" << std::endl;
	return (1);
}

int			NinjaTrap::ninjaShoebox(ClapTrap const &target)
{
	if (this->energy_points >= 25)
	{
		this->energy_points -= 25;
		std::cout << "NinjaTrap " << this->name << " threw his shoe on " << target << std::endl;
	}
	else
		std::cout << "NinjaTrap " << this->name << " doesn't have enough energy to execute his superpower!" << std::endl;
	return (1);
}

int			NinjaTrap::ninjaShoebox(FragTrap const &target)
{
	if (this->energy_points >= 25)
	{
		this->energy_points -= 25;
		std::cout << "NinjaTrap " << this->name << " threw his shoe on " << target << std::endl;
	}
	else
		std::cout << "NinjaTrap " << this->name << " doesn't have enough energy to execute his superpower!" << std::endl;
	return (1);
}

int			NinjaTrap::ninjaShoebox(ScavTrap const &target)
{
	if (this->energy_points >= 25)
	{
		this->energy_points -= 25;
		std::cout << "NinjaTrap " << this->name << " threw his shoe on " << target << std::endl;
	}
	else
		std::cout << "NinjaTrap " << this->name << " doesn't have enough energy to execute his superpower!" << std::endl;
	return (1);
}

std::ostream	&operator<<(std::ostream &o, NinjaTrap const &n)
{
	o << n.get_name();
	return (o);
}
