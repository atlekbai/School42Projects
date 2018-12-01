/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceThing.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:20:43 by atlekbai          #+#    #+#             */
/*   Updated: 2018/06/24 15:16:14 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPACE_THING_HPP
# define SPACE_THING_HPP

#include <iostream>
#include "Position.class.hpp"

class SpaceThing
{
public:

	SpaceThing & operator=(SpaceThing const & rhs);

	SpaceThing(void);
	SpaceThing(int, int);
	SpaceThing(const SpaceThing & toCopy);
	~SpaceThing(void){}
	void update(void);

	Position pos;
	Position	getPos(void) const;
	void		setPos(Position pos);
};

#endif