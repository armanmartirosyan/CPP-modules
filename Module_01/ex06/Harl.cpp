#include "Harl.hpp"

void Harl::complain(std::string level) {
	int			index = -1;
	int			functionSize = 4;
	std::string	functionName[] = {"DEBUG", "INFO" , "WARNING", "ERROR"}; 
	void		(Harl::*functionAddress[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	while (++index < functionSize && level != functionName[index]) {}
	switch (index)
	{
	case 0:
		(this->*(functionAddress[index++]))();
	case 1:
		(this->*(functionAddress[index++]))();
	case 2:
		(this->*(functionAddress[index++]))();
	case 3:
		(this->*(functionAddress[index]))();
		break;
	default:
		std::cout << "Complaining about something else." << std::endl;
		break;
	}
}

void Harl::debug(void) {
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-specialketchup";
	std::cout << " burger. I really do!" << std::endl;
	return ;
}

void Harl::info(void) {
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon";
	std::cout << " costs more money. You didn’t put";
	std::cout << " enough bacon in my burger! If you did,";
	std::cout << " I wouldn’t be asking for more!" << std::endl;
	return ;
}

void Harl::warning(void) {
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra ";
	std::cout << "bacon for free. I’ve been coming for years ";
	std::cout << "whereas you started working here since last month." << std::endl;
	return ;
}

void Harl::error(void) {
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want ";
	std::cout << "to speak to the manager now." << std::endl;
	return ;
}
