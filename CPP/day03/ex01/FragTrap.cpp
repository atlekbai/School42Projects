// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/21 12:58:22 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/21 12:58:23 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"
#include <ctime>

int		rand_phrase(std::string phrases[], int n)
{
	srand(time(NULL));
	std::cout << phrases[rand() % n] << std::endl;
	return (1);
}

FragTrap::FragTrap(std::string name) :	hit_points(100),
										max_hit_points(100),
										energy_points(100),
										max_energy_points(100),
										level(1),
										name(name),
										melee_attack_damage(30),
										ranged_attack_damage(20),
										armor_damage_reduction(5)
{
	std::string phrases[] = {
		"Hey everybody! Check out my package!",
		"Let's get this party started!",
		"Glitching weirdness is a term of endearment, right?",
		"Recompiling my combat code!",
		"This time it'll be awesome, I promise!",
		"Look out everybody! Things are about to get awesome!"
	};
	rand_phrase(phrases, 5);
}

FragTrap::FragTrap(FragTrap const &src)
{
	*this = src;
	std::string phrases[] = {
		"Hahaha... I ascend!"
		"Ha ha ha! I LIVE! Hahaha!",
		"Hahahahaha! I'm alive!",
		"Good, I didn't want any spare parts!",
		"Wow, that actually worked?",
		"You can't keep a good 'bot down!",
		"I'm back! Woo!",
		"Holy crap, that worked?",
		"Better lucky than good!",
		"Back for more!",
		"Here we go again!"
	};
	rand_phrase(phrases, 10);
}

FragTrap::~FragTrap(void)
{
	std::string phrases[] = {
		"I'll stop talking when I'm dead!",
		"I'll die the way I lived: annoying!",
		"Come back here! I'll gnaw your legs off!",
		"This could've gone better!",
		"You look like something a skag barfed up!",
		"What's that smell? Oh wait, it's just you!",
		"Yo momma's so dumb, she couldn't think of a good ending for this 'yo momma' joke!",
		"You're one screw short of a screw!",
		"I bet your mom could do better!",
		"You look like something a skag barfed up!",
		"Oh yeah? Well, uh... yeah.",
		"What is that smell? Oh, never mind... it's just you!",
		"I'm leaking!",
		"Good thing I don't have a soul!",
		"Aww!",
		"Aww! Come on!",
		"You can't kill me!",
		"I'm too pretty to die!",
		"Crap!",
		"Robot down!",
		"No, nononono NO!",
		"I'll never go back to the bad place!",
		"I have many regrets!"
	};
	rand_phrase(phrases, 22);
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
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

int			FragTrap::get_hit_points(void) const
{
	return (this->hit_points);
}

int			FragTrap::get_max_hit_points(void) const
{
	return (this->max_hit_points);
}

int			FragTrap::get_energy_points(void) const
{
	return (this->energy_points);
}

int			FragTrap::get_max_energy_points(void) const
{
	return (this->max_energy_points);
}

int			FragTrap::get_level(void) const
{
	return (this->level);
}

std::string	FragTrap::get_name(void) const
{
	return (this->name);
}

int			FragTrap::get_melee_attack_damage(void) const
{
	return (this->melee_attack_damage);
}

int			FragTrap::get_ranged_attack_damage(void) const
{
	return (this->ranged_attack_damage);
}

int			FragTrap::get_armor_damage_reduction(void) const
{
	return (this->armor_damage_reduction);
}

int			FragTrap::set_hit_points(int n)
{
	if (n < 0)
		return (0);
	if (n > this->max_hit_points)
		n = this->max_hit_points;
	this->hit_points = n;
	return (1);
}

int			FragTrap::set_max_hit_points(int n)
{
	if (n < 0)
		return (0);
	this->max_hit_points = n;
	return (1);
}

int			FragTrap::set_energy_points(int n)
{
	if (n < 0)
		return (0);
	if (n > this->max_energy_points)
		n = this->max_energy_points;
	this->energy_points = n;
	return (1);
}

int			FragTrap::set_max_energy_points(int n)
{
	if (n < 0)
		return (0);
	this->max_energy_points = n;
	return (1);
}

int			FragTrap::set_level(int n)
{
	if (level < 0)
		return (0);
	this->level = n;
	return (1);
}

int			FragTrap::set_name(std::string name)
{
	if (name.empty())
		return (0);
	this->name = name;
	return (1);
}

int			FragTrap::set_melee_attack_damage(int n)
{
	this->melee_attack_damage = n;
	return (1);
}

int			FragTrap::set_ranged_attack_damage(int n)
{
	this->ranged_attack_damage = n;
	return (1);
}

int			FragTrap::set_armor_damage_reduction(int n)
{
	this->armor_damage_reduction = n;
	return (1);
}

std::ostream	&operator<<(std::ostream &o, FragTrap const &f)
{
	o << f.get_name();
	return (o);
}

int			FragTrap::rangedAttack(std::string const & target)
{
	std::cout	<< "FR4G-TP " << this->name << " attacks "
				<< target << " at range, causing "
				<< this->ranged_attack_damage << " points of damage!"
				<< std::endl;
	return (1);
}

int			FragTrap::meleeAttack(std::string const & target)
{
	std::cout	<< "FR4G-TP " << this->name << " attacks "
				<< target << " at melee, causing "
				<< this->melee_attack_damage << " points of damage!"
				<< std::endl;
	return (1);
}

int			FragTrap::takeDamage(unsigned int amount)
{
	int	damage = 0;
	std::string phrases[] = {
		"Why do I even feel pain?!",
		"Why did they build me out of galvanized flesh?!",
		"Ow hohoho, that hurts! Yipes!",
		"My robotic flesh! AAHH!",
		"Yikes! Ohhoho!",
		"Woah! Oh! Jeez!",
		"If only my chassis... weren't made of recycled human body parts! Wahahaha!"
	};

	rand_phrase(phrases, 6);
	if ((int)amount >= this->armor_damage_reduction)
		damage = amount - this->armor_damage_reduction;
	else
		damage = 0;
	this->hit_points -= damage;
	return (1);
}

int			FragTrap::beRepaired(unsigned int amount)
{
	std::string phrases[] = {
		"Make my day.",
		"Gimme your best shot.",
		"Hit me, baby!",
		"Ya feeling lucky, punk?"
	};
	rand_phrase(phrases, 3);
	return (this->set_hit_points(this->hit_points + amount));
}

int			FragTrap::Clap_In_The_Box(std::string const & target)
{
	std::cout << this->name << " digistructs a large bomb on " << target << std::endl;
	return (1);
}

int			FragTrap::Torgue_Fiesta(std::string const & target)
{
	std::cout << this->name << " emit a series of live grenades in random directions to the front of him that damage " << target << std::endl;
	return (1);
}

int			FragTrap::One_Shot_Wonder(std::string const & target)
{
	std::cout << this->name << " unloads all ammo left in the magazine at once on " << target << std::endl;
	return (1);
}

int			FragTrap::Laser_Inferno(std::string const & target)
{
	std::cout << this->name << " is shooting shock, incendiary, and corrosive lasers at " << target << std::endl;
	return (1);
}

int			FragTrap::Meat_Unicycle(std::string const & target)
{
	std::cout << this->name << " pulls out a Buzz Axe for melee combat on " << target << std::endl;
	return (1);
}


int			FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	int 	(FragTrap::*attack[])(std::string const & target) = {
		&FragTrap::Clap_In_The_Box,
		&FragTrap::Torgue_Fiesta,
		&FragTrap::One_Shot_Wonder,
		&FragTrap::Laser_Inferno,
		&FragTrap::Meat_Unicycle
	};
	if (this->energy_points < 25)
	{
		std::string phrases[] = {
			"Where'd all my bullets go?",
			"Bullets are dumb.",
			"Who needs ammo anyway, am I right?",
			"I need tiny death pellets!",
			"Need some ammo!",
			"Dangit, I'm out!",
			"Ammo reserves are spent!",
			"Crap, no more shots left!",
			"Hnngh! Empty!",
			"Coming up empty!"
		};
		rand_phrase(phrases, 9);
		return (0);
	}
	this->energy_points -= 25;
	(this->*(attack[rand() % 4]))(target);
	return (1);
}
