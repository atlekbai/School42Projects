// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Logger.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 20:50:33 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/20 12:17:45 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Logger.hpp"
#include <sstream>

Logger::Logger(std::string name) : filename(name){}

Logger::~Logger(void){}

std::string	Logger::timeStamp(void)
{
	std::ostringstream	res;
	time_t				now = time(0);
	tm					*ltm = localtime(&now);

	res << "[";
	res << (1900 + ltm->tm_year);
	res << (((1 + ltm->tm_mon < 10) ? "0" : ""));
	res << (1 + ltm->tm_mon);
	res << (((ltm->tm_mday < 10) ? "0" : ""));
	res << (ltm->tm_mday);
	res << "_";
	res << ((ltm->tm_hour < 10) ? "0" : "");
	res << (ltm->tm_hour);
	res << (((ltm->tm_min < 10) ? "0" : ""));
	res << (ltm->tm_min);
	res << (((ltm->tm_sec < 10) ? "0" : ""));
	res << (ltm->tm_sec);
	res << "]";
	std::string str(res.str());
	return (str);
}

int			Logger::logToConsole(std::string str)
{
	std::cout << str << std::endl;
	return (1);
}

int			Logger::logToFile(std::string str)
{
	std::ofstream	ofs(this->filename, std::ios::app);

	ofs << str << std::endl;
	ofs.close();
	return (1);
}

std::string	Logger::makeLogEntry(std::string str)
{
	std::string	res;

	res.append(this->timeStamp());
	res.append(str);

	return (res);
}

int			Logger::log(std::string const &dest, std::string const &message)
{
	std::string	ops[] = {"console", "file"};
	int			(Logger::*funcs[])(std::string str) = {
		&Logger::logToConsole,
		&Logger::logToFile
	};
	std::string str = this->makeLogEntry(message);
	int			i = -1;

	while (++i < 2)
		if (ops[i] == dest)
		{
			(this->*(funcs[i]))(str);
			break ;
		}
	return (1);
}
