#include "Hostname.hpp"
#include <cstdlib>

Hostname::Hostname() : _hostname("hostname"), _time("echo $(date +%x:%r)"),
				 _os("sw_vers"), _cpu("sysctl -n machdep.cpu.brand_string"),
				_pro("top -l 1 | grep 'CPU usage:' |  cut -d' ' -f3"),
				_ram("top -l 1 | grep 'PhysMem:' |  cut -d' ' -f2"),
				_new_in("top -l 1 | grep 'Networks:' |  cut -d' ' -f3"),
				_new_out("top -l 1 | grep 'Networks:' |  cut -d' ' -f5"),
				_user("whoami")  { }

Hostname::~Hostname() { }

Hostname::Hostname (Hostname & src){
	*this = src;
}

Hostname const & Hostname::operator=(Hostname & rhs){
	_hostname = rhs.getHostname();
	 _time = rhs.getTime();
	 _os = rhs.getOs();
	 _cpu = rhs.getCPU();
	 _pro = rhs.getCPU_pro();
	 _ram = rhs.getRAM();
	 _new_in = rhs.getNetIn();
	 _new_out = rhs.getNetOut();
	 _user = rhs.getUser();
	 return (*this);
}

std::string Hostname::exec(const char* cmd){
	std::array<char, 128> buff;
    std::string rt;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);

    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buff.data(), 128, pipe.get()) != nullptr)
            rt += buff.data();
    }
    return rt;
}

std::string Hostname::getHostname(void){
	return (this->exec(_hostname.c_str()));
}

std::string Hostname::getTime(void){
	return (this->exec(_time.c_str()));
}

std::string Hostname::getOs(void){
	return (this->exec(_os.c_str()));
}

std::string Hostname::getCPU(void){
	return (this->exec(_cpu.c_str()));
}

std::string Hostname::getUser(void){
	return (this->exec(_user.c_str()));
}

int			 Hostname::getCPU_pro(void){
	return (atoi(this->exec(_pro.c_str()).c_str()));
}

int			 Hostname::getRAM(void){
	return (atoi(this->exec(_ram.c_str()).c_str()));
}

int			 Hostname::getNetIn(void){
	return (atoi(this->exec(_new_in.c_str()).c_str()));
}

int			 Hostname::getNetOut(void){
	return (atoi(this->exec(_new_out.c_str()).c_str()));
}