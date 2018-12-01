// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sorcerer.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 13:45:11 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 15:46:07 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
private:
	std::string	name;
	std::string title;
public:
	Sorcerer(std::string name, std::string title);
	~Sorcerer(void);
	Sorcerer(Sorcerer const &src);
	Sorcerer &operator=(Sorcerer const &src);

	std::string	getName(void) const;
	std::string	getTitle(void) const;
	void		polymorph(Victim const &v) const;
};

std::ostream &operator<<(std::ostream &o, Sorcerer const &s);
#endif
