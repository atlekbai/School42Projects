// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AMateria.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 20:22:18 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 20:22:18 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class ICharacter;

class AMateria
{
private:
	std::string		type;
	unsigned int	xp_;
public:
	AMateria(void);
	AMateria(std::string const &type);
	AMateria(AMateria const &src);
	~AMateria(void);
	AMateria &operator=(AMateria const &src);

	std::string	const	&getType(void) const;
	unsigned int		getXP(void) const;

	virtual AMateria	*clone(void) const = 0;
	virtual void		use(ICharacter &target) = 0;

	int					setXP(unsigned int xp);
	int					setType(std::string type);
	
};

#endif