/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceThing.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:20:43 by atlekbai          #+#    #+#             */
/*   Updated: 2018/06/24 15:26:58 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpaceThing.hpp"

SpaceThing::SpaceThing() {
	pos = Position();
}

SpaceThing::SpaceThing(const SpaceThing & toCopy) {
	this->pos = toCopy.pos;
}

SpaceThing::SpaceThing(int x, int y)
{
	pos.x = x;
	pos.y = y;
}
void SpaceThing::update(void)
{
	this->pos.y++;
}

Position	SpaceThing::getPos(void) const
{
	return (pos);
}

void		SpaceThing::setPos(Position pos)
{
	this->pos = pos;
}

SpaceThing & SpaceThing::operator=(SpaceThing const & rhs) {
	this->pos = rhs.pos;

	return *this;
}