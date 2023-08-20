#include "Intern.hpp"

// Constructors
Intern::Intern(void) {
	return ;
}

Intern::Intern(const Intern& rhs) {
	(void)rhs;
	return ;
}

// Destructor
Intern::~Intern(void) {
	return ;
}

// Operations
Intern& Intern::operator=(const Intern& rhs) {
	(void)rhs;
	return (*this);
}

// Functions
AForm*	Intern::makePresidentialPardonForm(const std::string& target) const {
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeShrubberyCreationForm(const std::string& target) const {
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeRobotomyRequestForm(const std::string& target) const {
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makeForm(const std::string& form, const std::string& target) const {
	const std::string formNames[3] = {"presidential pardon", "shrubbery creation", "robotomy request"};
	AForm*		(Intern::*functionAddress[3])(const std::string& target) const = {&Intern::makePresidentialPardonForm,
				&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm};
	size_t	i = 0;

	for (; form.compare(formNames[i]) && i < 3; i++)
		;
	if (i == 3)
		throw std::invalid_argument("No such form");
	return ((this->*functionAddress[i])(target));
}