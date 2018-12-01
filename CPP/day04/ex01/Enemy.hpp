// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/22 16:06:26 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/22 16:06:26 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

class Enemy
{
private:
	int			hp;
	std::string	type;
public:
	Enemy(int hp, std::string const &type);
	Enemy(Enemy const &src);
	virtual ~Enemy(void);
	Enemy &operator=(Enemy const &src);
	
	std::string		getType(void) const;
	int				getHP(void) const;

	int				setType(std::string type);
	int				setHP(int hp);
	virtual void	takeDamage(int damage);
};


#endif