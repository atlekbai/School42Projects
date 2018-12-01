/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:51:28 by atlekbai          #+#    #+#             */
/*   Updated: 2018/06/24 15:49:25 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(char disp_char,
				Position pos,
				Rect _end,
				int hp,
				int movingSpeed):GameEntity(disp_char, pos, _end, hp, movingSpeed)
{
	int i = -1;
	this->bullets = new Bullet*[100];
	while(++i < 100)
		this->bullets[i] = NULL;
}

Enemy::Enemy(const Enemy & toCopy):
GameEntity(toCopy.getDispChar(), toCopy.pos, toCopy.getRect(), toCopy.getHP(), toCopy.getSpeed()) { }

Enemy::Enemy(void){}
Enemy::~Enemy(void)
{
	delete (this->bullets);
}

Enemy & Enemy::operator=(Enemy const & rhs) {
	this->_disp_char = rhs._disp_char;
	this->pos = rhs.pos;
	this->_end = rhs._end;
	this->_hp = rhs._hp;
	this->_movingSpeed = rhs._movingSpeed;

	return *this;
}

std::ostream & operator<<(std::ostream & o, Enemy const & rhs)
{
	o << "<Enemy> HP[" << rhs.getHP() << "], Speed[" << rhs.getSpeed() << "], Position" << rhs.pos;
	return o;
}

void	Enemy::fire(void)
{
	int i = -1;

	while (++i < 100)
		if (this->bullets[i] == NULL)
			break;
	if (i == 100)
		return ;
	this->bullets[i] = new Bullet(this->pos.x, this->pos.y + 1);
	system("afplay sfx.wav&");
}

int		Enemy::eraseBullet(int i)
{
	delete (this->bullets[i]);
	this->bullets[i] = NULL;
	return (1);
}

int		Enemy::update(Rect field_end, int frame)
{
	int	i = -1;

	while (++i < 100)
		if (this->bullets[i] != NULL)
		{
			if (this->bullets[i]->getPos().y > field_end.bottom())
				this->eraseBullet(i);
			else
			{
				if (frame % 2 == 0)
					this->bullets[i]->update('+');
			}
		}
	if (frame % 30 == 0)
	{
		int x = rand() % 2;
		this->pos.y += 1;
		if (x == 0)
			this->pos.x += 2;
		else if (x == 1)
			this->pos.x -= 1;
	}
	if (rand() % 35 == 0)
		this->fire();
	return (1);
}
