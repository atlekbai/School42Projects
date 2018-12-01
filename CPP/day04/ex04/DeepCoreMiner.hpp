// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DeepCoreMiner.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 10:36:21 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/23 10:36:22 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef DEEPCOREMINER
# define DEEPCOREMINER

# include "IMiningLaser.hpp"

class DeepCoreMiner: public IMiningLaser
{
public:
	DeepCoreMiner(void);
	DeepCoreMiner(DeepCoreMiner const &src);
	~DeepCoreMiner(void);
	DeepCoreMiner &operator=(DeepCoreMiner const &src);

	void	mine(IAsteroid* a);
};


#endif