// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Victim.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 13:45:22 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 15:48:29 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim
{
protected:
	std::string	name;
public:
	Victim(std::string name);
	~Victim(void);
	Victim(Victim const &src);
	Victim	&operator=(Victim const &src);

	std::string	getName(void) const;
	void		getPolymorphed(void) const;
};

std::ostream	&operator<<(std::ostream &o, Victim const &v);

#endif
