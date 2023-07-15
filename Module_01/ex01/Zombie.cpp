#include "Zombie.hpp"

Zombie::Zombie(){
	std::cout << "Zombie!(created)" << std::endl;
}

Zombie::~Zombie(void){
	std::cout << this->_name << " is dead!" << std::endl;
}

void	Zombie::announce(void) const{
	std::cout << this->_name << ":BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::setName(const std::string name){
	this->_name = name;
	return ;
}
