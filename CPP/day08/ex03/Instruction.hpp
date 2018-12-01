// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Instruction.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/28 20:20:02 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/28 20:20:03 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef INSTRUCTION_HPP
# define INSTRUCTION_HPP

# include <iostream>
# include <vector>

class Instruction
{
private:
	char				mem[30000];
	unsigned			j;
public:
	Instruction(void);
	~Instruction(void);
	void	execute(char ch);
	char	&operator[](int index);
	unsigned getCurrent(void) const;
};

#endif