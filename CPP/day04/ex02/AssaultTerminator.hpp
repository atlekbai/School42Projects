// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AssaultTerminator.hpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 18:27:45 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 18:27:45 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include "ISpaceMarine.hpp"

class AssaultTerminator: public ISpaceMarine
{
public:
	AssaultTerminator(void);
	AssaultTerminator(AssaultTerminator const &src);
	~AssaultTerminator(void);

	ISpaceMarine*	clone(void) const;
	void			battleCry(void) const;
	void			rangedAttack(void) const;
	void			meleeAttack(void) const;
	
};

#endif