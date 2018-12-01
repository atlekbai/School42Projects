// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Squad.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 18:27:22 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 18:27:22 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Squad.hpp"

Squad::Squad(void) : n(0){}

Squad::Squad(Squad const &src)
{
	*this = src;
}

Squad::~Squad(void)
{
	int	i = -1;
	while (++i < this->n)
		delete (this->marines[i]);
	delete (this->marines);
}

Squad			&Squad::operator=(Squad const &src)
{
	int i = -1;
	int n = this->n;

	this->n = src.getCount();
	while (++i < n)
		delete (this->marines[i]);
	delete this->marines;
	i = -1;
	this->marines = new ISpaceMarine*[this->n];
	while (++i < this->n)
		this->push(src.getUnit(i));
	return (*this);
}

int				Squad::getCount(void) const
{
	return (this->n);
}

ISpaceMarine*	Squad::getUnit(int n) const
{
	if (n < 0 || n > this->n)
		return (NULL);
	return (this->marines[n]);
}

int				Squad::checkPush(ISpaceMarine* m)
{
	int i = -1;
	while (++i < this->n)
		if (this->marines[i] == m)
		{
			std::cout << "Marine already in squad" << std::endl;
			return (0);
		}
	return (1);
}

int				Squad::push(ISpaceMarine* m)
{
	ISpaceMarine	**army;

	if (!m || !this->checkPush(m))
		return (this->n);
	if (this->n > 0)
	{
		int	i = -1;

		army = new ISpaceMarine*[this->n + 1];
		while (++i < this->n)
			army[i] = this->marines[i];
		army[i] = m;
		i = -1;
		delete (this->marines);
		this->marines = army;
	}
	else
	{
		this->marines = new ISpaceMarine*[1];
		this->marines[0] = m;
	}
	this->n++;
	return (this->n);
}
