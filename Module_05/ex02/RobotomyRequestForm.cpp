#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm(void) :
AForm ("(Robotomy)", "Robotomy Request Form", 72, 45) {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name) :
AForm (name, "Robotomy Request Form", 72, 45) {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) :
AForm (rhs.getName(), rhs.getType(), rhs.getSignRequired(), rhs.getExecuteRequired()) {
	return ;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm(void) {
	return ;
}

// Operations
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	if (this == &rhs)
		return (*this);
	this->setIsSigned(rhs.getIsSigned());
	return (*this);
}

// Functions
void	RobotomyRequestForm::beSigned(const Bureaucrat& b) {
	if (this->getIsSigned()) {
		std::cout << "Form is already signed!" << std::endl;
		return ;
	}
	if (b.getGrade() > this->getSignRequired())
		throw GradeException("RobotomyRequestForm::GradeTooLowException");
	b.signForm(*this);
	return ;
}

void	RobotomyRequestForm::execute(const Bureaucrat& b) const {
	time_t currentTime = time(NULL);
	struct tm *localTime = localtime(&currentTime);
	if (!this->getIsSigned()) {
		std::cout << this->getName() << " form need to sign." << std::endl;
		return ;
	}
	if (b.getGrade() <= this->getExecuteRequired())
	{
		std::cout << "*(some drilling noises)*" << std::endl;
		if (localTime->tm_sec % 2)
			std::cout << this->getName() << " has been robotomized" << std::endl;
		else
			std::cout << this->getName() << " the robotomy failed" << std::endl;
		
	}
	else
		throw GradeException("RobotomyRequestForm::GradeTooLowException");
	return ;
}