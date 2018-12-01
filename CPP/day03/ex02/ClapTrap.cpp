// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/21 17:37:47 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/21 17:37:48 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) :	name(name),
										max_hit_points(0),
										energy_points(0),
										max_energy_points(0),
										level(0),
										melee_attack_damage(0),
										ranged_attack_damage(0),
										armor_damage_reduction(0)
{
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &rhs)
{
	*this = rhs;
	std::cout << "ClapTrap " << this->name << " copied" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->name << " destroyed" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
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

int			ClapTrap::get_hit_points(void) const
{
	return (this->hit_points);
}

int			ClapTrap::get_max_hit_points(void) const
{
	return (this->max_hit_points);
}

int			ClapTrap::get_energy_points(void) const
{
	return (this->energy_points);
}

int			ClapTrap::get_max_energy_points(void) const
{
	return (this->max_energy_points);
}

int			ClapTrap::get_level(void) const
{
	return (this->level);
}

std::string	ClapTrap::get_name(void) const
{
	return (this->name);
}

int			ClapTrap::get_melee_attack_damage(void) const
{
	return (this->melee_attack_damage);
}

int			ClapTrap::get_ranged_attack_damage(void) const
{
	return (this->ranged_attack_damage);
}

int			ClapTrap::get_armor_damage_reduction(void) const
{
	return (this->armor_damage_reduction);
}

int			ClapTrap::set_hit_points(int n)
{
	if (n < 0)
		return (0);
	if (n > this->max_hit_points)
		n = this->max_hit_points;
	this->hit_points = n;
	return (1);
}

int			ClapTrap::set_max_hit_points(int n)
{
	if (n < 0)
		return (0);
	this->max_hit_points = n;
	return (1);
}

int			ClapTrap::set_energy_points(int n)
{
	if (n < 0)
		return (0);
	if (n > this->max_energy_points)
		n = this->max_energy_points;
	this->energy_points = n;
	return (1);
}

int			ClapTrap::set_max_energy_points(int n)
{
	if (n < 0)
		return (0);
	this->max_energy_points = n;
	return (1);
}

int			ClapTrap::set_level(int n)
{
	if (level < 0)
		return (0);
	this->level = n;
	return (1);
}

int			ClapTrap::set_name(std::string name)
{
	if (name.empty())
		return (0);
	this->name = name;
	return (1);
}

int			ClapTrap::set_melee_attack_damage(int n)
{
	this->melee_attack_damage = n;
	return (1);
}

int			ClapTrap::set_ranged_attack_damage(int n)
{
	this->ranged_attack_damage = n;
	return (1);
}

int			ClapTrap::set_armor_damage_reduction(int n)
{
	this->armor_damage_reduction = n;
	return (1);
}

int			ClapTrap::rangedAttack(std::string const & target)
{
	std::cout	<< "ClapTrap " << this->name << " attacks "
				<< target << " at range, causing "
				<< this->ranged_attack_damage << " points of damage!"
				<< std::endl;
	return (1);
}

int			ClapTrap::meleeAttack(std::string const & target)
{
	std::cout	<< "ClapTrap " << this->name << " attacks "
				<< target << " at melee, causing "
				<< this->melee_attack_damage << " points of damage!"
				<< std::endl;
	return (1);
}

int			ClapTrap::takeDamage(unsigned int amount)
{
	int	damage = 0;

	if ((int)amount >= this->armor_damage_reduction)
		damage = amount - this->armor_damage_reduction;
	else
		damage = 0;
	if (damage > this->hit_points)
		this->hit_points = 0;
	else
		this->hit_points -= damage;
	std::cout << "ClapTrap " << this->name << " took " << damage << " damage" << std::endl;
	return (1);
}

int			ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " repaired" << std::endl;
	return (this->set_hit_points(this->hit_points + amount));
}

std::ostream	&operator<<(std::ostream &o, ClapTrap const &f)
{
	o << f.get_name();
	return (o);
}
