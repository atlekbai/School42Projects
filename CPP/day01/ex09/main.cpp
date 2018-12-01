// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/06/19 20:50:43 by atlekbai          #+#    #+#             //
//   Updated: 2018/06/20 12:11:47 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Logger.hpp"

int	main(void)
{
	Logger logger("logs");

	logger.log("file", "Logger initialized");
	logger.log("file", "Programm executed");
	logger.log("console", "Logs written to file");
	logger.log("console", "Please 100%");
	return (1);
}
