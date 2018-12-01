// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DeepCoreMiner.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 10:36:18 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/23 10:36:18 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "DeepCoreMiner.hpp"

DeepCoreMiner::DeepCoreMiner(void){}

DeepCoreMiner::DeepCoreMiner(DeepCoreMiner const &src)
{
	*this = src;
}

DeepCoreMiner::~DeepCoreMiner(void){}


void	DeepCoreMiner::mine(IAsteroid* a)
{
	std::cout << "* mining deep ... got " << a->beMined() << " ! *" << std::endl;
}
