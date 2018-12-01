// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IAsteroid.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/23 10:36:29 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/23 10:36:29 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IASTEROID
# define IASTEROID

# include <iostream>

class IAsteroid
{
public:
	virtual ~IAsteroid(void);
	virtual std::string	beMined(void) const = 0;
	virtual	std::string	getName(void) const = 0;
};

#endif