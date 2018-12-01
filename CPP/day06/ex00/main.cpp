// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/26 14:58:21 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/26 15:51:37 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "main.hpp"

int	convert(std::string parm)
{
	char	c;
	int		i;
	float	f;
	double	d;

	if (parm.find("fun") != std::string::npos || parm.find("0x") != std::string::npos)
	{
		std::cout << "Error: Unknown parameter" << std::endl;
		return (0);
	}
	if (isInt(parm))
	{
		try
		{
			i = std::stoi(parm);
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			std::cout << "char: ";
			if (i > 127 || i < 0)
				std::cout << "impossible" << std::endl;
			else if (c <= 32)
				std::cout << "Non displayable" << std::endl;
			else
				std::cout << "\'" << c << "\'" << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << "float: " << f << ".0f" << std::endl;
			std::cout << "double: " << d << ".0" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else if (isFloat(parm))
	{
		f = std::stof(parm);
		i = static_cast<int>(f);
		c = static_cast<char>(f);
		d = static_cast<double>(f);
		std::cout << "char: ";
		if (parm == "nanf" || parm == "+inff" || parm == "-inff" || i > 127|| d > 2147483647 || d < -2147483648)
			std::cout << "impossible" << std::endl;
		else if (c <= 32)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "\'" << c << "\'" << std::endl;
		std::cout << "int: ";
		if (parm == "nanf" || parm == "+inff" || parm == "-inff" || d > 2147483647 || d < -2147483648)
			std::cout << "impossible" << std::endl;
		else
			std::cout << i << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else if (isDouble(parm))
	{
		d = std::stod(parm);
		i = static_cast<int>(d);
		c = static_cast<char>(d);
		f = static_cast<float>(d);
		std::cout << "char: ";
		if (parm == "nan" || parm == "+inf" || parm == "-inf" || i > 127 || d > 2147483647 || d < -2147483648)
			std::cout << "impossible" << std::endl;
		else if (c <= 32)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "\'" << c << "\'" << std::endl;
		std::cout << "int: ";
		if (parm == "nan" || parm == "+inf" || parm == "-inf" || d > 2147483647 || d < -2147483648)
			std::cout << "impossible" << std::endl;
		else
			std::cout << i << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else if (isChar(parm))
	{
		c = parm[0];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
		std::cout << "char: ";
		if (c <= 32)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "\'" << c << "\'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else
		std::cout << "Error: Unknown parameter" << std::endl;	
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		convert(std::string (av[1]));
	else
		std::cout << "Usage: ./convert <some value>" << std::endl;
	return (0);
}
