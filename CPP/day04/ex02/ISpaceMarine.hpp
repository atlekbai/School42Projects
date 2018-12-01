// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ISpaceMarine.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 18:27:56 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 18:27:56 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ISPACEMARINE_HPP
# define ISPACEMARINE_HPP

# include <iostream>

class ISpaceMarine
{
public:
	virtual ~ISpaceMarine(void){}
	virtual ISpaceMarine*	clone(void) const = 0;
	virtual void			battleCry(void) const = 0;
	virtual void			rangedAttack(void) const = 0;
	virtual void			meleeAttack(void) const = 0;
};

#endif