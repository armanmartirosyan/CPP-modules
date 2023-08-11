#include "Cat.hpp"

// Constructors
Cat::Cat(void) : Animal::Animal() {
	this->setType("(Cat)");
	this->_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
	return ;
}

Cat::Cat(const Cat& rhs) : Animal::Animal(rhs) {
	this->setType("(Cat)");
	this->_brain = new Brain();
	*this->_brain = rhs.getCatBrain();
	std::cout << "Cat copy constructor called" << std::endl;
	return ;
}

Cat& Cat::operator=(const Cat& rhs) {
	Animal::operator=(rhs);
	*this->_brain = rhs.getCatBrain();
	std::cout << "Cat copy assignment constructor." << std::endl;
	return (*this);
}

// Destructor
Cat::~Cat(void) {
	std::cout << "Cat default destructor called" << std::endl;
	delete this->_brain;
	return ;
}

// Functinos
void	Cat::makeSound(void) const {
	std::cout << "Cat: MEOW, MEOOOOOOOW!" << std::endl;
	return ;
}

// Getters
std::string Cat::getCatIdea(const size_t& i) const {
	return (this->_brain->getIdea(i));
}

Brain&	Cat::getCatBrain(void) const {
	return *(this->_brain);
}

// Setters
void	Cat::setCatIdea(size_t i, const std::string& idea) {
	this->_brain->setIdea(i, idea);
	return ;
}

void Cat::setCatBrain(const Brain& newBrain) {
    *(this->_brain) = newBrain;
	return ;
}
