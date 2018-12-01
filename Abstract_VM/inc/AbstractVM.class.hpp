// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AbstractVM.class.hpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/07/10 15:53:51 by atlekbai          #+#    #+#             //
//   Updated: 2018/07/10 15:53:51 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ABTRACT_HPP
# define ABTRACT_HPP

# include <iostream>
# include "IOperand.hpp"
# include "Factory.class.hpp"
# include <vector>
# include <map>

class AbstractVM
{
private:
	Factory							factory;
	std::vector<const IOperand *>	v;
	unsigned int					iter;
	bool							quit;
	bool							has_error;
	bool							has_exit;

public:
	AbstractVM(void);
	AbstractVM(AbstractVM const &vm);
	AbstractVM &operator=(AbstractVM const &vm);
	~AbstractVM(void);

	bool			getExit(void) const;
	bool			getHasError(void) const;
	bool			getHasExit(void) const;
	void			toggleExit(void);
	void			defaultIter(void);

	void			push(eOperandType type, std::string const &str);
	void			assert(eOperandType type, std::string const &str);

	void			add(void);
	void			sub(void);
	void			mul(void);
	void			div(void);
	void			mod(void);
	void			pop(void);
	void			dump(void);
	void			print(void);
	void			exit(void);
	void			avrg(void);
	void			sum(void);
	void			sort(void);
	void			min(void);
	void			max(void);

	void			process(std::string const &line);
	void			validate(std::string const &line);
	eOperandType	getType(std::string const &type);

	class AssertFailException: public std::exception
	{
		private:
			const char *s1;
			const char *s2;
		public:
			AssertFailException(const char *s1, const char *s2) : s1(s1), s2(s2) {}
			const char *what() const throw()
			{
				char *a = new char[strlen("Error: assertion failed ~~> ") + strlen(s1)
								 	+ strlen(" != ") + strlen(s2) + 1];
				strcpy(a, "Error: assertion failed ~~> ");
				strcat(a, s1);
				strcat(a, " != ");
				strcat(a, s2);
				return (a);
			}
	};

	class PrintException: public std::exception
	{
		private:
			const char *s1;
		public:
			PrintException(const char *s1) : s1(s1) {}
			const char *what() const throw()
			{
				char *a = new char[strlen("Error: print command failed ~~> ") + strlen(s1)
									 	+ strlen(" is not Int8.") + 1];
				strcpy(a, "Error: print command failed ~~> ");
				strcat(a, s1);
				strcat(a, " is not Int8.");
				return (a);
			}
	};
	
	class StackIsEmptyException: public std::exception
	{
		private:
			std::string s1;

		public:
			StackIsEmptyException(std::string s1) : s1(s1) {}
			const char *what() const throw()
			{
				char *a = new char[strlen("Error: stack is empty, line ") + strlen(s1.c_str()) + 1];
				strcpy(a, "Error: stack is empty, line ");
				strcat(a, s1.c_str());
				return (a);
			}
	};

	class OperandsNotEnoughException: public std::exception
	{
		private:
			std::string s1;

		public:
			OperandsNotEnoughException(std::string s1) : s1(s1) {}
			const char *what() const throw()
			{
				char *a = new char[strlen("Error: not enough operands, line ") + strlen(s1.c_str()) + 1];
				strcpy(a, "Error: not enough operands, line ");
				strcat(a, s1.c_str());
				return (a);
			}
	};

	class LexicalErrorException: public std::exception
	{
		private:
			std::string s1;
			std::string s2;

		public:
			LexicalErrorException(std::string s1, std::string s2) : s1(s1), s2(s2) {}
			const char *what() const throw()
			{
				char *a = new char[strlen("Error: on line No.") + strlen(s1.c_str()) + strlen(" ~~~~> ") + strlen(s2.c_str()) + 1];
				strcpy(a, "Error: on line No.");
				strcat(a, s1.c_str());
				strcat(a, " ~~~~> ");
				strcat(a, s2.c_str());
				return (a);
			}
	};

	class DoubleExitException: public std::exception
	{
		private:
			std::string s1;

		public:
			DoubleExitException(std::string s1) : s1(s1) {}
			const char *what() const throw()
			{
				char *a = new char[strlen("Error: more than one exit, line No.") + strlen(s1.c_str()) + 1];
				strcpy(a, "Error: more than one exit, line No.");
				strcat(a, s1.c_str());
				return (a);
			}
	};

	class NoExitException: public std::exception
	{
		const char *what() const throw()
		{
			return ("Error: no exit command found");
		}
	};
};

#endif