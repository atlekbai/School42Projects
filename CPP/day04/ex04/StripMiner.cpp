// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   StripMiner.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 10:37:02 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/23 10:37:02 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "StripMiner.hpp"

StripMiner::StripMiner(void){}

StripMiner::StripMiner(StripMiner const &src)
{
	*this = src;
}

StripMiner::~StripMiner(void){}


void	StripMiner::mine(IAsteroid* a)
{
	std::cout << "* strip mining ... got " << a->beMined() << " ! *" << std::endl;
}
