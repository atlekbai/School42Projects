/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:51:22 by atlekbai          #+#    #+#             */
/*   Updated: 2018/06/24 15:19:01 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "GameEntity.class.hpp"
#include "Bullet.hpp"

class Enemy: public GameEntity
{
public:
	Bullet **bullets;

	Enemy & operator=(Enemy const & rhs);

	Enemy(char disp_char, Position pos, Rect _end, int hp, int movingSpeed);
	Enemy(const Enemy & toCopy);
	Enemy(void);
	~Enemy(void);
	void	fire(void);
	int		eraseBullet(int i);
	int		update(Rect, int frame);
};

std::ostream & operator<<(std::ostream & o, Enemy const & rhs);

#endif
