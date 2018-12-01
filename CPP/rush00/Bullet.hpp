/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtarasen <rtarasen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 17:11:56 by atlekbai          #+#    #+#             */
/*   Updated: 2018/06/24 15:13:57 by rtarasen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

#include "SpaceThing.hpp"

class Bullet: public SpaceThing
{
	
public:

	Bullet & operator=(Bullet const & rhs);

	Bullet(int, int);
	Bullet(const Bullet & toCopy);
	~Bullet(void){}
	void update(char c);
};

#endif