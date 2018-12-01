// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 16:06:17 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 16:06:18 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
private:
	std::string name;
	int			ap;
	AWeapon		*weapon;

public:
	Character(std::string const &name);
	Character(Character const &src);
	~Character(void);
	Character	&operator=(Character const &src);
	
	void		recoverAP(void);
	void		equip(AWeapon* weapon);
	void		attack(Enemy* enemy);
	std::string	getName(void) const;
	int			getAp(void) const;
	AWeapon		*getWeapon(void) const;
};

std::ostream &operator<<(std::ostream &o, Character const &c);

#endif