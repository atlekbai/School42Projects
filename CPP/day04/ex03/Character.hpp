// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 20:23:05 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 20:23:06 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CHARACTER
# define CHARACTER

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter
{
private:
	std::string name;
	AMateria	**inventory;

public:
	Character(std::string name);
	Character(Character const &src);
	~Character(void);
	Character 			&operator=(Character const &src);
	std::string const	&getName() const;
	void 				equip(AMateria* m);
	void 				unequip(int idx);
	void 				use(int idx, ICharacter& target);

	AMateria			**getInventory(void) const;
};

#endif