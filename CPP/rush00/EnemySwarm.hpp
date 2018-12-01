/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemySwarm.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 13:35:37 by atlekbai          #+#    #+#             */
/*   Updated: 2018/06/24 15:29:14 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_SWARM_HPP
# define ENEMY_SWARM_HPP

#include "Rect.hpp"
#include "Enemy.hpp"


class EnemySwarm
{
private:
	Rect		field_end;
	Enemy		**objects;
	int			n;

public:
	EnemySwarm(const EnemySwarm& toCopy);
	EnemySwarm(void);
	~EnemySwarm(void);

	EnemySwarm &operator=(EnemySwarm const & rhs);

	void update(int frame);
	void erase(unsigned);
	void setend(Rect);

	Enemy **getData(void) const;
	int			addData(Enemy *s);
	int			getN(void) const;
};

#endif
