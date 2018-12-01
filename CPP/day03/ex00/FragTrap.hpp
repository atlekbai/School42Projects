// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/21 12:58:31 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/21 12:58:32 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>

class FragTrap
{
private:
	int			hit_points;
	int			max_hit_points;
	int			energy_points;
	int			max_energy_points;
	int			level;
	std::string	name;
	int			melee_attack_damage;
	int			ranged_attack_damage;
	int			armor_damage_reduction;
public:
	FragTrap(std::string name);
	FragTrap(FragTrap const &src);
	~FragTrap(void);
	FragTrap	&operator=(FragTrap const &rhs);

	int			rangedAttack(std::string const & target);
	int			meleeAttack(std::string const & target);
	int			takeDamage(unsigned int amount);
	int			beRepaired(unsigned int amount);
	int			vaulthunter_dot_exe(std::string const & target);

	int			Clap_In_The_Box(std::string const & target);
	int			Torgue_Fiesta(std::string const & target);
	int			One_Shot_Wonder(std::string const & target);
	int			Laser_Inferno(std::string const & target);
	int			Meat_Unicycle(std::string const & target);

	int			get_hit_points(void) const;
	int			get_max_hit_points(void) const;
	int			get_energy_points(void) const;
	int			get_max_energy_points(void) const;
	int			get_level(void) const;
	std::string	get_name(void) const;
	int			get_melee_attack_damage(void) const;
	int			get_ranged_attack_damage(void) const;
	int			get_armor_damage_reduction(void) const;

	int			set_hit_points(int n);
	int			set_max_hit_points(int n);
	int			set_energy_points(int n);
	int			set_max_energy_points(int n);
	int			set_level(int n);
	int			set_name(std::string name);
	int			set_melee_attack_damage(int n);
	int			set_ranged_attack_damage(int n);
	int			set_armor_damage_reduction(int n);
};

std::ostream &operator<<(std::ostream &o, FragTrap const &f);

#endif