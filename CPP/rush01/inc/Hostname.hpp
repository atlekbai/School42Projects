#ifndef HOSTNAME_H
# define HOSTNAME_H

#include "IMonitorModule.hpp"

class Hostname : public IMonitorModule{
public:
	Hostname(void);
	~Hostname(void);
	virtual std::string getHostname(void);
	virtual std::string getTime(void);
	virtual std::string getOs(void);
	virtual std::string getCPU(void);
	int			 		getCPU_pro(void);
	int					getRAM(void);
	int					getNetIn(void);
	int					getNetOut(void);
	std::string			getUser(void);
private:
	Hostname (Hostname & src);
	Hostname const & operator=(Hostname & rhs);
	virtual std::string	exec(const char* cmd);
	std::string _hostname;
	std::string _time;
	std::string _os;
	std::string _cpu;
	std::string _pro;
	std::string _ram;
	std::string _new_in;
	std::string _new_out;
	std::string _user;
};

#endif