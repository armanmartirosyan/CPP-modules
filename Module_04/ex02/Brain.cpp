#include "Brain.hpp"

// Constructors
Brain::Brain(void) {
	std::cout << "I may not have a brain, gentlemen, but I have an idea.";
	std::cout << "(Brain default constructor)" << std::endl;
	return ;
}

Brain::Brain(const Brain& rhs) {
	std::cout << "I may not have a brain, gentlemen, but I have an idea.";
	std::cout << "(Brain copy constructor)" << std::endl;
	for (size_t i = 0; i < IDLIMIT; i++)
		this->_ideas[i] = rhs.getIdea(i);
	return ;
}

// Destructor
Brain::~Brain(void) {
	std::cout << "(Brain Destructor)" << std::endl;
	return ;
}

// Operation
Brain& Brain::operator=(const Brain& rhs) {
	if (this == &rhs)
		return (*this);
	std::cout << "I may not have a brain, gentlemen, but I have an idea.";
	std::cout << "(Brain copy assignment constructor)" << std::endl;
	for (size_t i = 0; i < IDLIMIT; i++)
		this->_ideas[i] = rhs.getIdea(i);
	return (*this);
}

// Getters
std::string	Brain::getIdea(size_t i) const {
	return (this->_ideas[i % 100]);
}

// Setters
void	Brain::setIdea(size_t i, const std::string& idea) {
	this->_ideas[i % 100] = idea;
	return ;
}

