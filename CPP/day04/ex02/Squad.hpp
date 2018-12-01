// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Squad.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 18:27:25 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 18:27:25 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"

class Squad: public ISquad
{
private:
	int				n;
	ISpaceMarine**	marines;

public:
	Squad(void);
	Squad(Squad const &src);
	~Squad(void);
	Squad			&operator=(Squad const &src);

	int				getCount(void) const;
	ISpaceMarine*	getUnit(int n) const;
	int				push(ISpaceMarine* m);
	int				checkPush(ISpaceMarine* m);
	
};

#endif