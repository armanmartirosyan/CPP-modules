#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm(void) :
AForm("(Presidential)", "Presidential Pardon Form", 25, 5){
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name) :
AForm(name, "Presidential Pardon Form", 25, 5) {
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) :
AForm(rhs.getName(), rhs.getType(), rhs.getSignRequired(), rhs.getExecuteRequired()) {
	return ;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm(void) {
	return ;
}

// Operations
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	if (this == &rhs)
		return (*this);
	this->setIsSigned(rhs.getIsSigned());
	return (*this);
}

// Functions
void	PresidentialPardonForm::beSigned(const Bureaucrat& b) {
	if (this->getIsSigned()) {
		std::cout << "Form is already signed!" << std::endl;
		return ;
	}
	if (b.getGrade() > this->getSignRequired())
		throw GradeException("PresidentialPardonForm::GradeTooLowException");
	b.signForm(*this);
	return ;
}

void	PresidentialPardonForm::execute(const Bureaucrat& b) const {
	if (!this->getIsSigned()) {
		std::cout << this->getName() << " form need to sign." << std::endl;
		return ;
	}
	if (b.getGrade() <= this->getExecuteRequired())
		std::cout << this->getName()<< " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else
		throw GradeException("PresidentialPardonForm::GradeTooLowException");
	return ;
}