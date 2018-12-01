// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Boss.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/24 15:29:12 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/24 15:29:12 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BOSS_HPP
# define BOSS_HPP

#include "GameEntity.class.hpp"
#include "Bullet.hpp"

class Boss: public GameEntity
{
public:
	Bullet **bullets;
	
	Boss(char disp_char, Position pos, Rect _end, int hp, int movingSpeed);
	Boss &operator=(Boss const &src);
	Boss(Boss const &src);
	Boss(void);
	~Boss(void);
	int		fire(int x, int y);
	int		eraseBullet(int i);
	int		update(Rect, int frame, Position player);
	Bullet  **getBullets(void) const;
};

std::ostream & operator<<(std::ostream & o, Boss const & rhs);

#endif