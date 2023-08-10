#include "Dog.hpp"

// Constructors
Dog::Dog(void) : Animal::Animal() {
	this->setType("(Dog)");
	this->_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
	return ;
}

Dog::Dog(const Dog& rhs) : Animal::Animal(rhs) {
	this->setType("(Dog)");
	this->_brain = new Brain();
	*this->_brain = rhs.getDogBrain();
	std::cout << "Dog copy constructor called" << std::endl;
	return ;
}

Dog& Dog::operator=(const Dog& rhs) {
	Animal::operator=(rhs);
	*this->_brain = rhs.getDogBrain();
	std::cout << "Animal copy assignment constructor." << std::endl;
	return (*this);
}

// Destructor
Dog::~Dog(void) {
	std::cout << "Dog default destructor called" << std::endl;
	delete this->_brain;
	return ;
}

// Functinos
void	Dog::makeSound(void) const {
	std::cout << "Dog: haf, haf?" << std::endl;
	return ;
}

// Getters
std::string Dog::getDogIdea(const size_t& i) const {
	return (this->_brain->getIdea(i));
}

Brain&	Dog::getDogBrain(void) const {
	return *(this->_brain);
}

// Setters
void	Dog::setDogIdea(size_t i, const std::string& idea) {
	this->_brain->setIdea(i, idea);
	return ;
}

void Dog::setDogBrain(const Brain& newBrain) {
    *(this->_brain) = newBrain;
	return ;
}
