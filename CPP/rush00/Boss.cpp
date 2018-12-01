// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Boss.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/24 15:29:04 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/24 15:29:04 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Boss.hpp"

Boss::Boss(char disp_char,
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

Boss::Boss(void){}
Boss::~Boss(void)
{
	delete (this->bullets);
}

Boss &Boss::operator=(Boss const &src)
{
	this->bullets = src.getBullets();
	return (*this);
}

Boss::Boss(Boss const &src)
{
	*this = src;
}

std::ostream & operator<<(std::ostream & o, Boss const & rhs)
{
	o << "<Boss> HP[" << rhs.getHP() << "], Speed[" << rhs.getSpeed() << "], Position" << rhs.pos;
	return o;
}

int	Boss::fire(int x, int y)
{
	int i = -1;

	while (++i < 100)
		if (this->bullets[i] == NULL)
			break;
	if (i == 100)
		return 0;
	this->bullets[i] = new Bullet(x, y);
	system("afplay blast.wav&");
	return (1);
}

int		Boss::eraseBullet(int i)
{
	delete (this->bullets[i]);
	this->bullets[i] = NULL;
	return (1);
}

int		Boss::update(Rect field_end, int frame, Position player)
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
	if (frame % 10 == 0)
	{
		int y = rand() % 2;

		if (this->pos.y < field_end.top() + 5)
			this->pos.y++;
		else if (this->pos.y > field_end.top() + 20)
			this->pos.y--;
		else
		{
			if (y == 0)
				this->pos.y += 1;
			else if (y == 1)
				this->pos.y -= 1;
		}

		if (this->pos.x > player.x)
			this->pos.x -= 2;
		else if (this->pos.x < player.x)
			this->pos.x += 2;
	}
	(rand() % 87 == 0) ? this->fire(this->pos.x, this->pos.y + 1) : 0;
	(rand() % 170 == 0) ? this->fire(this->pos.x + 2, this->pos.y + 1) : 0;
	(rand() % 107 == 0) ? this->fire(this->pos.x - 2, this->pos.y + 1) : 0;
	(rand() % 107 == 0) ? this->fire(this->pos.x - 4, this->pos.y + 1), this->fire(this->pos.x + 4, this->pos.y + 1) : 0;
	return (1);
}

Bullet  **Boss::getBullets(void) const
{
	return (this->bullets);
}
