/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 21:23:45 by atlekbai          #+#    #+#             */
/*   Updated: 2018/06/24 15:43:39 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

Player::Player(char disp_char,
				Position pos,
				Rect _end,
				int hp,
				int movingSpeed):GameEntity(disp_char, pos, _end, hp, movingSpeed)
{
	this->destroyed = 0;
	this->killed = 0;
	int i = -1;
	this->bullets = new Bullet*[100];
	while(++i < 100)
		this->bullets[i] = NULL;
}

Player::Player(const Player & toCopy): GameEntity(toCopy) {
	this->destroyed = toCopy.destroyed;
	this->killed = toCopy.killed;
}

Player::Player(void){}
Player::~Player(void)
{
	delete (this->bullets);
}

Player & Player::operator=(Player const & rhs) {
	this->_disp_char = rhs._disp_char;
	this->_end = rhs._end;
	this->_hp = rhs._hp;
	this->_movingSpeed = rhs._movingSpeed;
	this->killed = rhs.killed;
	this->destroyed = rhs.destroyed;

	return *this;
}

std::ostream & operator<<(std::ostream & o, Player const & rhs)
{
	o << "<Player> HP[" << rhs.getHP() << "], Speed[" << rhs.getSpeed() << "], Position" << rhs.pos;
	return o;
}

void	Player::fire(void)
{
	int i = -1;

	while (++i < 100)
		if (this->bullets[i] == NULL)
			break;
	if (i == 100)
		return ;
	this->bullets[i] = new Bullet(this->pos.x, this->pos.y);
	system("afplay laser.wav&");
}

int		Player::getDestroyed(void) const
{
	return (this->destroyed);
}

int		Player::getKilled(void) const
{
	return (this->killed);
}

int		Player::addDestroyed(void)
{
	this->destroyed++;
	return (1);
}

int		Player::addKilled(void)
{
	this->killed++;
	return (1);
}

int		Player::eraseBullet(int i)
{
	delete (this->bullets[i]);
	this->bullets[i] = NULL;
	return (1);
}

int		Player::checkBullets(Rect field_end)
{
	int	i = -1;

	while (++i < 100)
		if (this->bullets[i] != NULL)
		{
			if (this->bullets[i]->getPos().y < field_end.top())
				this->eraseBullet(i);
			else
				this->bullets[i]->update('-');
		}
	return (1);
}
