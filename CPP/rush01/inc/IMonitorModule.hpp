#ifndef IMONITORMODULE_H
# define IMONITORMODULE_H

#include <string>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <array>


class IMonitorModule{
	public:
		virtual std::string getHostname(void) = 0;
		virtual std::string getTime(void) = 0;
		virtual std::string getOs(void) = 0;
		virtual std::string	exec(const char* cmd) = 0;
};

#endif