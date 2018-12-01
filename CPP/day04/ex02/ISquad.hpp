// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ISquad.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 18:28:01 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 18:28:01 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ISQUAD_HPP
# define ISQUAD_HPP

# include <iostream>
# include "ISpaceMarine.hpp"

class ISquad
{
public:
	virtual ~ISquad(void){}
	virtual int				getCount(void) const = 0;
	virtual ISpaceMarine*	getUnit(int) const = 0;
	virtual int				push(ISpaceMarine*) = 0;
};


#endif
