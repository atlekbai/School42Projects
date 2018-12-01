/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 21:23:51 by atlekbai          #+#    #+#             */
/*   Updated: 2018/06/24 15:38:02 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_HPP
# define PLAYER_CLASS_HPP

#include "GameEntity.class.hpp"
#include "Bullet.hpp"

class Player: public GameEntity
{
private:
	int	destroyed;
	int	killed;
public:
	Bullet **bullets;

	Player &operator=(Player const & rhs);

	Player(char disp_char, Position pos, Rect _end, int hp, int movingSpeed);
	Player(const Player & toCopy);
	Player(void);
	~Player(void);
	void	fire(void);
	int		getDestroyed(void) const;
	int		getKilled(void) const;
	int		addDestroyed(void);
	int		addKilled(void);
	int		eraseBullet(int i);
	int		checkBullets(Rect);
};

std::ostream & operator<<(std::ostream & o, Player const & rhs);

#endif
