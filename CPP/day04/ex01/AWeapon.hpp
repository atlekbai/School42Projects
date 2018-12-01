// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AWeapon.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 16:06:08 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 16:06:09 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>

class AWeapon
{
private:
	std::string name;
	int			apcost;
	int			damage;

public:
	AWeapon(std::string const &name, int apcost, int damage);
	AWeapon(AWeapon const &src);
	virtual ~AWeapon();
	AWeapon &operator=(AWeapon const &src);
	
	std::string			getName(void) const;
	int					getAPCost(void) const;
	int					getDamage(void) const;

	int					setName(std::string name);
	int					setAPCost(int apcost);
	int					setDamage(int damage);
	virtual void		attack(void) const = 0;
};

#endif