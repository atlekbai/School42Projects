/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 17:11:53 by atlekbai          #+#    #+#             */
/*   Updated: 2018/06/24 15:26:43 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet & Bullet::operator=(Bullet const & rhs) {
	this->pos = rhs.pos;
	return *this;
}

Bullet::Bullet(const Bullet & toCopy) {
	this->pos = toCopy.pos;
}

Bullet::Bullet(int x, int y): SpaceThing(x, y) {}

void Bullet::update(char c)
{
	Position pos = this->getPos();
	if (c == '-')
		pos.y--;
	else if (c == '+')
		pos.y++;
	this->setPos(pos);
}
