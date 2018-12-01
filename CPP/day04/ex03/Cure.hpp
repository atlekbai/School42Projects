// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Cure.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 20:22:46 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 20:22:46 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure: public AMateria
{
public:
	Cure(void);
	Cure(Cure const &src);
	~Cure(void);
	Cure 				&operator=(Cure const &src);

	Cure				*clone(void) const;
	void				use(ICharacter &target);
	
};

#endif