/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 21:24:15 by atlekbai          #+#    #+#             */
/*   Updated: 2018/06/24 15:25:07 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGAMEENTITY_CLASS_HPP
# define IGAMEENTITY_CLASS_HPP

#include "Position.class.hpp"
#include "Rect.hpp"

class GameEntity
{
protected:
	char		_disp_char;
	Rect		_end;
	int 		_hp;
	int 		_movingSpeed;

public:
	Position	pos;
	bool		isDead(void) const;
	bool		isCollidingWith(const GameEntity & entity) const;
	void 		takeDamage(int amount);
	void		update(int cycle);

	int 		getHP(void) const;
	int 		getSpeed(void) const;
	char 		getDispChar(void) const;
	Rect		getRect(void) const;

	void 		setHP(int amount);
	void 		setSpeed(int speed);
	void		setRect(Rect rec);

	GameEntity	&operator=(GameEntity const & rhs);
	GameEntity(const GameEntity& toCopy);
	GameEntity(char disp_char, Position pos, Rect _end, int hp, int movingSpeed);
	GameEntity(void);
	~GameEntity(void);

};

#endif
