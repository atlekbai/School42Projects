// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Peon.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 13:45:32 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 15:55:25 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"

class Peon: public Victim
{
public:
	Peon(std::string name);
	Peon(Peon const &src);
	~Peon(void);
	Peon	&operator=(Peon const &src);

	void	getPolymorphed(void) const;
};

#endif
