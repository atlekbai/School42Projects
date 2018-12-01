// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Brain.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 17:05:57 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/19 17:13:19 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>

class	Brain
{
public:
	Brain(void);
	~Brain(void);
	std::string	identify(void) const;

private:
	std::string	address;
};

#endif
