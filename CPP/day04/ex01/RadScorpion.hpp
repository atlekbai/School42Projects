// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RadScorpion.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 16:07:05 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 16:07:05 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include "Enemy.hpp"

class RadScorpion: public Enemy
{
public:
	RadScorpion(void);
	RadScorpion(RadScorpion const &src);
	~RadScorpion(void);
	RadScorpion &operator=(RadScorpion const &src);
};

#endif