// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperTrap.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/21 19:02:57 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/21 19:02:57 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name) :    ClapTrap(name)
{
    this->hit_points = 100;
	this->max_hit_points = 100;
	this->energy_points = 120;
	this->max_energy_points = 120;
	this->level = 1;
	this->melee_attack_damage = 60;
	this->ranged_attack_damage = 20;
	this->armor_damage_reduction = 5;
    std::cout << "SuperTrap " << this->name << " created." << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const &src):    ClapTrap(name)
{
    *this = src;
	std::cout << "SuperTrap " << this->name << " copied." << std::endl;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "SuperTrap " << this->name << " destroyed." << std::endl;
}

SuperTrap   &SuperTrap::operator=(SuperTrap const &rhs)
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

std::ostream &operator<<(std::ostream &o, SuperTrap const &f)
{
    o << f.get_name();
    return (o);
}
