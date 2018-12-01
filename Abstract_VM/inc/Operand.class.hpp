// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Operand.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/05 22:36:05 by atlekbai          #+#    #+#             //
//   Updated: 2018/07/05 22:42:22 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OPERAND_CLASS_HPP
# define OPERAND_CLASS_HPP

# include "IOperand.hpp"
# include "Factory.class.hpp"
# include <cmath>

template <typename T>
class Operand: public IOperand
{
private:
	std::string		str;
	Factory			factory;
	eOperandType	type;

	eOperandType	identifyType(void)
	{
		if (typeid(char) == typeid(T))
			return (Int8);
		else if (typeid(short int) == typeid(T))
			return (Int16);
		else if (typeid(int) == typeid(T))
			return (Int32);
		else if (typeid(float) == typeid(T))
			return (Float);
		else
			return (Double);
	}
	
	T				convert(std::string str) const
	{
		if (type == Int8)
			return (static_cast<char>(std::stoi(str)));
		else if (type == Int16)
			return (static_cast<short int>(std::stoi(str)));
		else if (type == Int32)
			return (std::stoi(str));
		else if (type == Float)
			return (std::stof(str));
		else
			return (std::stod(str));
	}

public:
	Operand(void) : str("0"), type(Int8){}
	Operand(T value) :	str(std::to_string(value)), type(identifyType()){}
	Operand(Operand const &src) : 	str(src.toString()),
									type(src.getType()){}

	Operand(const IOperand *rhs)
	{
		this->str = (*rhs).toString();
		this->type = (*rhs).getType();
	}
	
	Operand				&operator=(const IOperand *rhs)
	{
		this->str = (*rhs).toString();
		this->type = (*rhs).getType();
		return (*this);
	}

	Operand				&operator=(Operand const &rhs)
	{
		this->str = std::to_string(this->value);
		this->type = rhs.getType();
		return (*this);
	}

	~Operand(void){}
	

	int					getPrecision(void) const
	{
		return (static_cast<int>(type));
	}

	eOperandType		getType(void) const
	{
		return (this->type);
	}

	template <typename U>
	IOperand const*		operate(U a, U b, eOperandType type, char c) const
	{
		if (c == '-')
			return (factory.createOperand(type, std::to_string(a - b)));
		if (b == 0)
				throw DivisorZeroException();
		if (c == '/')
			return (factory.createOperand(type, std::to_string(a / b)));
		else
			if (typeid(U) == typeid(float) || typeid(U) == typeid(double))
				return (factory.createOperand(type, std::to_string(fmod(a, b))));
			else
				return (factory.createOperand(type, std::to_string(static_cast<int>(a) % static_cast<int>(b))));
	}

	template <typename U, typename V>
	bool				compare(U a, V b, char c) const
	{
		if (c == '=')
			return (a == b);
		else if (c == '<')
			return (a < b);
		else
			return (a > b);
	}

	IOperand const*		operator+(IOperand const &rhs) const
	{
		if (rhs.getPrecision() > this->getPrecision())
			return (rhs + *this);
		return (factory.createOperand(this->type, std::to_string(
			convert(rhs.toString()) + convert(this->str))
		));
	}


	IOperand const*		operator-(IOperand const &rhs) const
	{
		if (rhs.getPrecision() > this->getPrecision())
		{
			if (rhs.getType() == Int16)
				return (operate(static_cast<short int>(std::stoi(str)),
								static_cast<short int>(std::stoi(rhs.toString())),
								rhs.getType(),
								'-'));
			else if (rhs.getType() == Int32)
				return (operate(std::stoi(str), std::stoi(rhs.toString()), rhs.getType(), '-'));
			else if (rhs.getType() == Float)
				return (operate(std::stof(str), std::stof(rhs.toString()), rhs.getType(), '-'));
			else if (rhs.getType() == Double)
				return (operate(std::stod(str), std::stod(rhs.toString()), rhs.getType(), '-'));
		}
		return (factory.createOperand(this->type, std::to_string(
			 convert(this->str) - convert(rhs.toString()))
		));
	}

	IOperand const*		operator*(IOperand const &rhs) const
	{
		if (rhs.getPrecision() > this->getPrecision())
			return (rhs * *this);
		return (factory.createOperand(this->type, std::to_string(
			convert(rhs.toString()) * convert(this->str))
		));
	}

	IOperand const*		operator/(IOperand const &rhs) const
	{
		if (rhs.getPrecision() > this->getPrecision())
		{
			if (rhs.getType() == Int16)
				return (operate(static_cast<short int>(std::stoi(str)),
								static_cast<short int>(std::stoi(rhs.toString())),
								rhs.getType(),
								'/'));
			else if (rhs.getType() == Int32)
				return (operate(std::stoi(str), std::stoi(rhs.toString()), rhs.getType(), '/'));
			else if (rhs.getType() == Float)
				return (operate(std::stof(str), std::stof(rhs.toString()), rhs.getType(), '/'));
			else if (rhs.getType() == Double)
				return (operate(std::stod(str), std::stod(rhs.toString()), rhs.getType(), '/'));
		}
		if (convert(rhs.toString()) == 0)
				throw DivisorZeroException();
		return (factory.createOperand(this->type, std::to_string(
			 convert(this->str) / convert(rhs.toString()))
		));
	}

	IOperand const*		operator%(IOperand const &rhs) const
	{
		if (rhs.getPrecision() > this->getPrecision())
		{
			if (rhs.getType() == Int16)
				return (operate(static_cast<short int>(std::stoi(str)),
								static_cast<short int>(std::stoi(rhs.toString())),
								rhs.getType(),
								'%'));
			else if (rhs.getType() == Int32)
				return (operate(std::stoi(str), std::stoi(rhs.toString()), rhs.getType(), '%'));
			else if (rhs.getType() == Float)
				return (operate(std::stof(str), std::stof(rhs.toString()), rhs.getType(), '%'));
			else if (rhs.getType() == Double)
				return (operate(std::stod(str), std::stod(rhs.toString()), rhs.getType(), '%'));
		}
		if (convert(rhs.toString()) == 0)
				throw DivisorZeroException();
		return (factory.createOperand(this->type, std::to_string(
			 fmod(convert(this->str), convert(rhs.toString())))
		));
	}

	bool				operator==(IOperand const &rhs) const
	{
		if (rhs.getType() == Int8)
			return (compare(convert(this->str),
							static_cast<char>(std::stoi(rhs.toString())), '='));
		if (rhs.getType() == Int16)
			return (compare(convert(this->str),
							static_cast<short int>(std::stoi(rhs.toString())), '='));
		else if (rhs.getType() == Int32)
			return (compare(convert(this->str), std::stoi(rhs.toString()), '='));
		else if (rhs.getType() == Float)
			return (compare(convert(this->str), std::stof(rhs.toString()), '='));
		else
			return (compare(convert(this->str), std::stod(rhs.toString()), '='));
	}

	bool				operator>(IOperand const &rhs) const
	{
		if (rhs.getType() == Int8)
			return (compare(convert(this->str),
							static_cast<char>(std::stoi(rhs.toString())), '>'));
		if (rhs.getType() == Int16)
			return (compare(convert(this->str),
							static_cast<short int>(std::stoi(rhs.toString())), '>'));
		else if (rhs.getType() == Int32)
			return (compare(convert(this->str), std::stoi(rhs.toString()), '>'));
		else if (rhs.getType() == Float)
			return (compare(convert(this->str), std::stof(rhs.toString()), '>'));
		else
			return (compare(convert(this->str), std::stod(rhs.toString()), '>'));
	}
	
	bool				operator<(IOperand const &rhs) const
	{
		if (rhs.getType() == Int8)
			return (compare(convert(this->str),
							static_cast<char>(std::stoi(rhs.toString())), '<'));
		if (rhs.getType() == Int16)
			return (compare(convert(this->str),
							static_cast<short int>(std::stoi(rhs.toString())), '<'));
		else if (rhs.getType() == Int32)
			return (compare(convert(this->str), std::stoi(rhs.toString()), '<'));
		else if (rhs.getType() == Float)
			return (compare(convert(this->str), std::stof(rhs.toString()), '<'));
		else
			return (compare(convert(this->str), std::stod(rhs.toString()), '<'));
	}

	std::string const	&toString(void) const
	{
		return (str);
	}

	class DivisorZeroException: public std::exception
	{
		const char *what() const throw()
		{
			return ("Error: divisor zero");
		}
	};
};

#endif
