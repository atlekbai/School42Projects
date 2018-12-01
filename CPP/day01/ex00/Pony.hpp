// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pony.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 14:19:14 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/19 14:19:15 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>

class Pony
{
public:
	Pony();
	~Pony();

	std::string	getName(void) const;
	std::string	getColor(void) const;
	unsigned	getAge(void) const;
	int			getCornLength(void) const;
	int			setName(std::string name);
	int			setColor(std::string color);
	int			setAge(unsigned age);
	int			setCornLength(int corn_length);

private:
	std::string	name;
	std::string	color;
	unsigned	age;
	int			corn_length;
};

#endif