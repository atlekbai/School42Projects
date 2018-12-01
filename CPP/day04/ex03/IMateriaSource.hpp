// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMateriaSource.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 20:23:56 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 20:23:56 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMATERIASOURCE
# define IMATERIASOURCE

# include <iostream>
# include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource(void) {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif