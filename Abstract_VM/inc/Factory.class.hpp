// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Factory.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/09 14:33:05 by atlekbai          #+#    #+#             //
//   Updated: 2018/07/09 14:33:05 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FACTORY
# define FACTORY

# include "IOperand.hpp"

class Factory
{
private:
	IOperand const	*createInt8		(std::string const &value) const;
	IOperand const	*createInt16	(std::string const &value) const;
	IOperand const	*createInt32	(std::string const &value) const;
	IOperand const	*createFloat	(std::string const &value) const;
	IOperand const	*createDouble	(std::string const &value) const;
public:
	IOperand const	*createOperand	(eOperandType type, std::string const &value) const;
};

#endif