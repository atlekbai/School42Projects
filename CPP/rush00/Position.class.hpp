// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Position.class.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 21:23:35 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/23 21:23:36 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef POSITION_CLASS_HPP
# define POSITION_CLASS_HPP

#include <iostream>

class Position {

public:
	int x;
	int y;

	Position & operator=(Position const & rhs);
	bool operator==(Position const & rhs) const;
	Position(void);
	Position(int x, int y);
	Position(const Position & toCopy);
	~Position(void);

};

std::ostream & operator<<(std::ostream & o, Position const & rhs);

#endif
