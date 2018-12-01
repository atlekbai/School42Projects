// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MateriaSource.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 20:23:18 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 20:23:19 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MATERIASOURCE
# define MATERIASOURCE

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
	AMateria	**source;

public:
	MateriaSource(void);
	MateriaSource(MateriaSource const &src);
	~MateriaSource(void) {}
	MateriaSource &operator=(MateriaSource const &src);
	void learnMateria(AMateria* a);
	AMateria* createMateria(std::string const & type);

	AMateria	**getSource(void) const;
};

#endif