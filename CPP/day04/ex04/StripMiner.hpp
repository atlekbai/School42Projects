// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   StripMiner.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 10:37:04 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/23 10:37:05 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef STRIPMINER
# define STRIPMINER

# include "IMiningLaser.hpp"

class StripMiner: public IMiningLaser
{
public:
	StripMiner(void);
	StripMiner(StripMiner const &src);
	~StripMiner(void);
	StripMiner &operator=(StripMiner const &src);

	void	mine(IAsteroid* a);
};


#endif