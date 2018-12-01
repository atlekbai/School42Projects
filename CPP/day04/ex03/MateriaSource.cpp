// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MateriaSource.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 20:23:16 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 20:23:16 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	this->source = new AMateria*[4];
	this->source[0] = NULL;
	this->source[1] = NULL;
	this->source[2] = NULL;
	this->source[3] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	delete (this->source);
	*this = src;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &src)
{
	delete (this->source);
	this->source = src.getSource();
	return (*this);
}

void		MateriaSource::learnMateria(AMateria* a)
{
	int i = -1;

	while (++i < 4)
		if (this->source[i] == NULL)
			break ;
	if (i == 4)
		return ;
	this->source[i] = a;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	int i = -1;

	while (++i < 4)
	{
		if (this->source[i]->getType() == type)
			break ;
	}
	if (i == 4)
		return (NULL);
	return (this->source[i]);
}

AMateria	**MateriaSource::getSource(void) const
{
	return (this->source);
}
