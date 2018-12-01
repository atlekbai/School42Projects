// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 20:02:41 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/19 20:21:56 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Human.hpp"

int	main(void)
{
	Human human;

	human.action("meleeAttack", "Goblin");
	human.action("rangedAttack", "Ghost");
	human.action("intimidatingShout", "Troll");
	return (0);
}
