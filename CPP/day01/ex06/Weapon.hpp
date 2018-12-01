// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Weapon.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 18:30:59 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/19 19:08:51 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
public:
	Weapon(std::string type);
	~Weapon(void);
	const std::string	&getType(void);
	void		setType(std::string type);

private:
	std::string	type;
};

#endif
