// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 17:06:07 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/19 17:25:24 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>
# include "Brain.hpp"

class	Human
{
public:
	Human();
	~Human(void);
	std::string identify(void) const;
	Brain		getBrain(void) const;

private:
	const Brain brain;
};

#endif
