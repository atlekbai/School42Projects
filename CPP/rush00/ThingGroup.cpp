/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ThingGroup.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 13:37:45 by atlekbai          #+#    #+#             */
/*   Updated: 2018/06/24 15:35:55 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ThingGroup.hpp"

ThingGroup::ThingGroup(void)
{
	int i = -1;
	this->n = 100;
	this->field_end = Rect(0, 0, 0, 0);
	this->objects = new SpaceThing*[this->n];
	while (++i < this->n)
		this->objects[i] = NULL;
}

ThingGroup::ThingGroup(const ThingGroup & toCopy) {
	this->field_end = toCopy.field_end;
	this->objects = toCopy.objects;
	this->n = toCopy.n;
}

ThingGroup::~ThingGroup(void)
{
	delete (this->objects);
}

ThingGroup & ThingGroup::operator=(ThingGroup const & rhs) {
	this->field_end = rhs.field_end;
	this->objects = rhs.objects;
	this->n = rhs.n;

	return *this;
}

void ThingGroup::update(void)
{
	int	i = -1;

	while (++i < this->n)
		if (this->objects[i] != NULL)
		{
			if (this->objects[i]->getPos().y > field_end.bottom())
				this->erase(i);
			else
				this->objects[i]->update();
		}
	SpaceThing *s = new SpaceThing(rand() % field_end.width(), 0);
	this->addData(s);
}

void ThingGroup::erase(unsigned i)
{
	delete (this->objects[i]);
	this->objects[i] = NULL;
}

void ThingGroup::setend(Rect s)
{
	this->field_end = s;
}

SpaceThing **ThingGroup::getData(void) const
{
	return (this->objects);
}

int			ThingGroup::addData(SpaceThing *s)
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

int			ThingGroup::getN(void) const
{
	return (this->n);
}
