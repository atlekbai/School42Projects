// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AbstractVM.class.cpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/10 15:53:54 by atlekbai          #+#    #+#             //
//   Updated: 2018/07/10 15:53:54 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AbstractVM.class.hpp"
#include <regex>

AbstractVM::AbstractVM(void) : iter(0), quit(false), has_error(false), has_exit(false) {}
AbstractVM::~AbstractVM(void){}

AbstractVM::AbstractVM(AbstractVM const &vm)
{
	if (this != &vm)
		*this = vm;
}

AbstractVM &AbstractVM::operator=(AbstractVM const &vm)
{
	this->quit = vm.getExit();
	this->has_error = vm.getHasError();
	this->has_exit = vm.getHasExit();
	return (*this);
}

bool			AbstractVM::getExit(void) const
{
	return (this->quit);
}

bool			AbstractVM::getHasError(void) const
{
	if (!this->has_exit)
		throw NoExitException();
	return (this->has_error);
}

bool			AbstractVM::getHasExit(void) const
{
	return (this->has_exit);
}

void			AbstractVM::toggleExit(void)
{
	this->quit = true;
}

void			AbstractVM::defaultIter(void)
{
	this->iter = 0;
}

void			AbstractVM::process(std::string const &line)
{
	std::map <std::string, void (AbstractVM::*)(eOperandType type, std::string const &str)> opr_exec = {
		{"push", &AbstractVM::push},
		{"assert", &AbstractVM::assert},
	};
	std::map <std::string, void (AbstractVM::*)()> cmd_exec = {
		{"add", &AbstractVM::add},
		{"sub", &AbstractVM::sub},
		{"mul", &AbstractVM::mul},
		{"div", &AbstractVM::div},
		{"mod", &AbstractVM::mod},
		{"pop", &AbstractVM::pop},
		{"dump", &AbstractVM::dump},
		{"print", &AbstractVM::print},
		{"exit", &AbstractVM::exit},
		{"avrg", &AbstractVM::avrg},
		{"sum", &AbstractVM::sum},
		{"sort", &AbstractVM::sort},
		{"min", &AbstractVM::min},
		{"max", &AbstractVM::max}
	};
	std::smatch	match;
	std::regex	opr("[ \t]*((push)|(assert))[ \t]+?((int8)|(int16)|(int32)|(float)|(double))[ \t]*?\\(([-]?[0-9]*.[0-9]*)\\)[ \t]*([;].*)?");
	std::regex	cmd("[ \t]*((add)|(sub)|(mul)|(div)|(mod)|(pop)|(dump)|(print)|(exit)|(avrg)|(sum)|(sort)|(min)|(max))[ \t]*([;].*)?");
	std::regex	comm("[ \t]*([;].*)?");
	this->iter++;
	if (regex_match(line, opr))
	{
		std::regex_search(line.begin(), line.end(), match, opr);
		(this->*opr_exec[match.str(1)])(getType(match.str(4)), match.str(10));
	}
	else if (regex_match(line, cmd))
	{
		std::regex_search(line.begin(), line.end(), match, cmd);
		(this->*cmd_exec[match.str(1)])();
	}
	else if (regex_match(line, comm))
		NULL;
	else
		throw LexicalErrorException(std::to_string(this->iter), line);
}

void			AbstractVM::validate(std::string const &line)
{
	std::smatch smatch;
	std::regex	opr("[ \t]*((push)|(assert))[ \t]+?((int8)|(int16)|(int32)|(float)|(double))[ \t]*?\\(([-]?[0-9]*[.]?[0-9]*)\\)[ \t]*([;].*)?");
	std::regex	cmd("[ \t]*((add)|(sub)|(mul)|(div)|(mod)|(pop)|(dump)|(print)|(exit)|(avrg)|(sum)|(sort)|(min)|(max))[ \t]*([;].*)?");
	std::regex	comm("[ \t]*([;].*)?");

	this->iter++;
	if (!regex_match(line, opr) && !regex_match(line, cmd) && !regex_match(line, comm))
	{
		has_error = true;
		throw LexicalErrorException(std::to_string(this->iter), line);
	}
	else if (regex_match(line, cmd) && line.find("exit") != std::string::npos)
	{
		if (has_exit)
		{
			has_error = true;
			throw DoubleExitException(std::to_string(this->iter));
		}
		has_exit = true;
	}
}

eOperandType	AbstractVM::getType(std::string const &type)
{
	std::map <std::string, eOperandType> types = {
		{"int8", Int8},
		{"int16", Int16},
		{"int32", Int32},
		{"float", Float},
		{"double", Double}
	};

	return (types[type]);
}

void			AbstractVM::push(eOperandType type, std::string const &str)
{
	v.push_back(factory.createOperand(type, str));
}

void			AbstractVM::assert(eOperandType type, std::string const &str)
{
	if (v.empty())
		throw StackIsEmptyException(std::to_string(this->iter).c_str());
	
	const IOperand *ass = factory.createOperand(type, str);
	if (!(*ass == *v.back()))
		throw AssertFailException(str.c_str(), v.back()->toString().c_str());
}

void			AbstractVM::add(void)
{
	if (v.size() < 2)
		throw OperandsNotEnoughException(std::to_string(this->iter));

	const IOperand *a = v.back();
	v.pop_back();
	const IOperand *b = v.back();
	v.pop_back();
	const IOperand *c = *b + *a;
	push(c->getType(), c->toString());
	delete a;
	delete b;
	delete c;
}

void			AbstractVM::sub(void)
{
	if (v.size() < 2)
		throw OperandsNotEnoughException(std::to_string(this->iter));

	const IOperand *a = v.back();
	v.pop_back();
	const IOperand *b = v.back();
	v.pop_back();
	const IOperand *c = *b - *a;
	push(c->getType(), c->toString());
	delete a;
	delete b;
	delete c;
}

void			AbstractVM::mul(void)
{
	if (v.size() < 2)
		throw OperandsNotEnoughException(std::to_string(this->iter));

	const IOperand *a = v.back();
	v.pop_back();
	const IOperand *b = v.back();
	v.pop_back();
	const IOperand *c = *b * *a;
	push(c->getType(), c->toString());
	delete a;
	delete b;
	delete c;
}

void			AbstractVM::div(void)
{
	if (v.size() < 2)
		throw OperandsNotEnoughException(std::to_string(this->iter));

	const IOperand *a = v.back();
	v.pop_back();
	const IOperand *b = v.back();
	v.pop_back();
	try
	{
		const IOperand *c = *b / *a;
		push(c->getType(), c->toString());
		delete c;
	}
	catch (std::exception &e)
	{
		toggleExit();
		std::cout << e.what() << ", line " << this->iter << std::endl;
	}
	delete a;
	delete b;
}

void			AbstractVM::mod(void)
{
	if (v.size() < 2)
		throw OperandsNotEnoughException(std::to_string(this->iter));

	const IOperand *a = v.back();
	v.pop_back();
	const IOperand *b = v.back();
	v.pop_back();
	try
	{
		const IOperand *c = *b % *a;
		push(c->getType(), c->toString());
		delete c;
	}
	catch (std::exception &e)
	{
		toggleExit();
		std::cout << e.what() << ", line " << this->iter << std::endl;
	}
	delete a;
	delete b;
}

void			AbstractVM::pop(void)
{
	if (v.empty())
		throw StackIsEmptyException(std::to_string(this->iter));
	v.pop_back();
}

void			AbstractVM::dump(void)
{
	for (int i = v.size() - 1; i >= 0; i--)
		std::cout << v[i]->toString() << std::endl;
}

void			AbstractVM::print(void)
{
	if (v.empty())
		throw StackIsEmptyException(std::to_string(this->iter));

	const IOperand *a = v.back();
	if (a->getType() != Int8)
		throw PrintException(a->toString().c_str());
	std::cout << static_cast<char>(std::stoi(a->toString()));
}

void			AbstractVM::exit(void)
{
	quit = true;
}

void			AbstractVM::avrg(void)
{
	if (v.empty())
		throw StackIsEmptyException(std::to_string(this->iter));
	
	const IOperand *c = factory.createOperand(Int32, std::to_string(0));
	for(size_t i = 0; i < v.size(); i++)
		c = *c + *(v[i]);
	c = *c / *factory.createOperand(c->getType(), std::to_string(v.size()));
	std::cout << c->toString() << std::endl;
}

void			AbstractVM::sum(void)
{
	if (v.empty())
		throw StackIsEmptyException(std::to_string(this->iter));

	const IOperand *c = factory.createOperand(Int32, std::to_string(0));
	for(size_t i = 0; i < v.size(); i++)
		c = *c + *(v[i]);
	std::cout << c->toString() << std::endl;
}

void			AbstractVM::sort(void)
{
	for (size_t i = 0; i < v.size(); i++)
		for (size_t j = 0; j < v.size(); j++)
			if (i != j && *v[i] > *v[j])
			{
				const IOperand *tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
}

void			AbstractVM::min(void)
{
	if (!v.empty())
	{
		const IOperand *c = factory.createOperand(Int32, std::to_string(2147483647));
		for(size_t i = 0; i < v.size(); i++)
			if (*c > *(v[i]))
				c = v[i];
		std::cout << c->toString() << std::endl;
	}
}

void			AbstractVM::max(void)
{
	if (!v.empty())
	{
		const IOperand *c = factory.createOperand(Int32, std::to_string(0));
		for(size_t i = 0; i < v.size(); i++)
			if (*c < *v[i])
				c = v[i];
		std::cout << c->toString() << std::endl;
	}
}


