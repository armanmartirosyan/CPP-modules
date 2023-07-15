#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->_name = name;
	std::cout << "Zombie!(created)" << std::endl;
}

Zombie::~Zombie(void){
	std::cout << this->_name << " is dead!" << std::endl;
}

void	Zombie::announce(void) const{
	std::cout << this->_name << ":BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
