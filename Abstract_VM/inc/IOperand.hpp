// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IOperand.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/02 19:35:14 by atlekbai          #+#    #+#             //
//   Updated: 2018/07/05 22:35:56 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IOPERAND_HPP
# define IOPERAND_HPP

# include <iostream>

enum eOperandType {Int8, Int16, Int32, Float, Double};

class IOperand
{
public:
	virtual int					getPrecision(void) const = 0;
	virtual eOperandType		getType(void) const = 0;

	virtual IOperand const*		operator+(IOperand const &rhs) const = 0;
	virtual IOperand const*		operator-(IOperand const &rhs) const = 0;
	virtual IOperand const*		operator*(IOperand const &rhs) const = 0;
	virtual IOperand const*		operator/(IOperand const &rhs) const = 0;
	virtual IOperand const*		operator%(IOperand const &rhs) const = 0;
	virtual bool				operator==(IOperand const &rhs) const = 0;
	virtual bool				operator>(IOperand const &rhs) const = 0;
	virtual bool				operator<(IOperand const &rhs) const = 0;

	virtual std::string const	&toString(void) const = 0;
	virtual						~IOperand(void){}
};

#endif
