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

ScavTrap::ScavTrap(std::string name) :	hit_points(100),
										max_hit_points(100),
										energy_points(50),
										max_energy_points(50),
										level(1),
										name(name),
										melee_attack_damage(20),
										ranged_attack_damage(15),
										armor_damage_reduction(3)
{
	std::cout << "ScavTrap " << name << " created." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src)
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

int			ScavTrap::get_hit_points(void) const
{
	return (this->hit_points);
}

int			ScavTrap::get_max_hit_points(void) const
{
	return (this->max_hit_points);
}

int			ScavTrap::get_energy_points(void) const
{
	return (this->energy_points);
}

int			ScavTrap::get_max_energy_points(void) const
{
	return (this->max_energy_points);
}

int			ScavTrap::get_level(void) const
{
	return (this->level);
}

std::string	ScavTrap::get_name(void) const
{
	return (this->name);
}

int			ScavTrap::get_melee_attack_damage(void) const
{
	return (this->melee_attack_damage);
}

int			ScavTrap::get_ranged_attack_damage(void) const
{
	return (this->ranged_attack_damage);
}

int			ScavTrap::get_armor_damage_reduction(void) const
{
	return (this->armor_damage_reduction);
}

int			ScavTrap::set_hit_points(int n)
{
	if (n < 0)
		return (0);
	if (n > this->max_hit_points)
		n = this->max_hit_points;
	this->hit_points = n;
	return (1);
}

int			ScavTrap::set_max_hit_points(int n)
{
	if (n < 0)
		return (0);
	this->max_hit_points = n;
	return (1);
}

int			ScavTrap::set_energy_points(int n)
{
	if (n < 0)
		return (0);
	if (n > this->max_energy_points)
		n = this->max_energy_points;
	this->energy_points = n;
	return (1);
}

int			ScavTrap::set_max_energy_points(int n)
{
	if (n < 0)
		return (0);
	this->max_energy_points = n;
	return (1);
}

int			ScavTrap::set_level(int n)
{
	if (level < 0)
		return (0);
	this->level = n;
	return (1);
}

int			ScavTrap::set_name(std::string name)
{
	if (name.empty())
		return (0);
	this->name = name;
	return (1);
}

int			ScavTrap::set_melee_attack_damage(int n)
{
	this->melee_attack_damage = n;
	return (1);
}

int			ScavTrap::set_ranged_attack_damage(int n)
{
	this->ranged_attack_damage = n;
	return (1);
}

int			ScavTrap::set_armor_damage_reduction(int n)
{
	this->armor_damage_reduction = n;
	return (1);
}

std::ostream	&operator<<(std::ostream &o, ScavTrap const &f)
{
	o << f.get_name();
	return (o);
}

int			ScavTrap::rangedAttack(std::string const & target)
{
	std::cout	<< "ScavTrap " << this->name << " attacks "
				<< target << " at range, causing "
				<< this->ranged_attack_damage << " points of damage!"
				<< std::endl;
	return (1);
}

int			ScavTrap::meleeAttack(std::string const & target)
{
	std::cout	<< "ScavTrap " << this->name << " attacks "
				<< target << " at melee, causing "
				<< this->melee_attack_damage << " points of damage!"
				<< std::endl;
	return (1);
}

int			ScavTrap::takeDamage(unsigned int amount)
{
	int	damage = 0;
	if ((int)amount >= this->armor_damage_reduction)
		damage = amount - this->armor_damage_reduction;
	else
		damage = 0;
	this->hit_points -= damage;
	std::cout << "ScavTrap " << this->name << " took " << damage << " damage. AAHHH!!!" << std::endl;
	return (1);
}

int			ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << "ScavTrap " << this->name << " was repaired " << amount << " hp. Mamamia!" << std::endl;
	return (this->set_hit_points(this->hit_points + amount));
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