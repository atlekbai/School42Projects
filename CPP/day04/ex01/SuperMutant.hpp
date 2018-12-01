// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperMutant.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 16:07:23 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 16:07:23 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant: public Enemy
{
public:
	SuperMutant(void);
	SuperMutant(SuperMutant const &src);
	~SuperMutant(void);
	SuperMutant &operator=(SuperMutant const &src);

	void	takeDamage(int n);
};


#endif