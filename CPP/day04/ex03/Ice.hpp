// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ice.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 20:22:39 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 20:22:39 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice: public AMateria
{
public:
	Ice(void);
	Ice(Ice const &src);
	~Ice(void);
	Ice 				&operator=(Ice const &src);

	Ice					*clone(void) const;
	void				use(ICharacter &target);
	
};

#endif
