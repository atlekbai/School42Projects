// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IMiningLaser.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 10:36:35 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/23 10:36:36 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IMININGLASER
# define IMININGLASER

# include <iostream>

class IAsteroid;

class IMiningLaser
{
public:
	virtual ~IMiningLaser(void){}
	virtual void	mine(IAsteroid*) = 0;
};


#endif