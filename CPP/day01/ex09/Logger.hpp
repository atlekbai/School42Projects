// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Logger.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 20:50:36 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/20 11:41:09 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <iostream>
# include <ctime>
# include <fstream>

class Logger
{
private:
	int			logToConsole(std::string str);
	int			logToFile(std::string str);
	std::string	makeLogEntry(std::string str);
	std::string	timeStamp(void);
	std::string filename;

public:
	Logger(std::string name);
	~Logger(void);
	int			log(std::string const &dest, std::string const &message);
	
};

#endif
