/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemySwarm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 13:35:40 by atlekbai          #+#    #+#             */
/*   Updated: 2018/06/24 15:32:10 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnemySwarm.hpp"

EnemySwarm::EnemySwarm(const EnemySwarm& toCopy) {
	this->field_end = toCopy.field_end;
	this->objects = toCopy.objects;
	this->n = toCopy.n;
}

EnemySwarm::EnemySwarm(void)
{
	int i = -1;
	this->n = 100;
	this->field_end = Rect(0, 0, 0, 0);
	this->objects = new Enemy*[this->n];
	while (++i < this->n)
		this->objects[i] = NULL;
}

EnemySwarm::~EnemySwarm(void)
{
	delete (this->objects);
}

EnemySwarm & EnemySwarm::operator=(EnemySwarm const & rhs) {
	this->field_end = rhs.field_end;
	this->objects = rhs.objects;
	this->n = rhs.n;

	return *this;
}

void EnemySwarm::update(int frame)
{
	int	i = -1;

	while (++i < this->n)
		if (this->objects[i] != NULL)
		{
			if (this->objects[i]->pos.y > field_end.bottom())
				this->erase(i);
			else
				this->objects[i]->update(field_end, frame);
		}
	if (frame % 100 == 0)
	{
		Enemy *s = new Enemy(Enemy('O', Position(rand() % field_end.width(), 0), Rect(0, 0, 3, 1), 100, 10000));
		this->addData(s);
	}
}

void EnemySwarm::erase(unsigned i)
{
	delete (this->objects[i]);
	this->objects[i] = NULL;
}

void EnemySwarm::setend(Rect s)
{
	this->field_end = s;
}

Enemy **EnemySwarm::getData(void) const
{
	return (this->objects);
}

int			EnemySwarm::addData(Enemy *s)
{
	int i = -1;

	while (++i < this->n)
		if (this->objects[i] == NULL)
			break ;
	if (i == this->n)
		return (0);
	this->objects[i] = s;
	return (1);
}

int			EnemySwarm::getN(void) const
{
	return (this->n);
}
