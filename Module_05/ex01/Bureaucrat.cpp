#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat(void){
	this->_name = "(default)";
	this->_grade = 150;
	return ;
}

Bureaucrat::Bureaucrat(int grade, const std::string& name) {
	this->_name = name;
	if (grade < 1)
		throw GradeException("Bureaucrat::GradeTooHighException");
	else if (grade > 150)
		throw GradeException("Bureaucrat::GradeTooLowException");
	this->_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) {
	this->_name = rhs.getName();
	this->_grade = rhs.getGrade();
	return ;
}

// Destructor
Bureaucrat::~Bureaucrat(void) {
	return ;	
}

// Operations
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (this == &rhs)
		return (*this);
	this->_grade = rhs.getGrade();
	this->_name = rhs.getName();	
	return (*this);
}

Bureaucrat& Bureaucrat::operator++(void) {
	if (this->_grade - 1 < 1)
		throw GradeException("Bureaucrat::GradeTooHighException");
	--this->_grade;
	return (*this);
}

Bureaucrat Bureaucrat::operator++(int) {
	Bureaucrat	clone(*this);

	if (this->_grade - 1 < 1)
		throw GradeException("Bureaucrat::GradeTooHighException");
	--this->_grade;
	return (clone);
}

Bureaucrat& Bureaucrat::operator--(void) {
	if (this->_grade + 1 > 150)
		throw GradeException("Bureaucrat::GradeTooLowException");
	++this->_grade;
	return(*this);
}

Bureaucrat Bureaucrat::operator--(int) {
	Bureaucrat	clone(*this);

	if (this->_grade + 1 > 150)
		throw GradeException("Bureaucrat::GradeTooLowException");
	++this->_grade;
	return (clone);
}

// Getters
std::string Bureaucrat::getName(void) const {
	return (this->_name);
}

int Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

// Setters
void	Bureaucrat::setName(const std::string& name) {
	this->_name = name;
	return ;
}

void	Bureaucrat::setGrade(int grade) {
	if (grade < 1)
		throw GradeException("Bureaucrat::GradeTooHighException");
	else if (grade > 150)
		throw GradeException("Bureaucrat::GradeTooLowException");
	this->_grade = grade;
	return ;
}

// Functions
void	Bureaucrat::signForm(Form& form) const {
	if (form.getIsSigned()) {
		std::cout << "Form is already signed!" << std::endl;
		return ;
	}
	if (this->getGrade() <= form.getSignRequired()) {
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
		form.setIsSigned(true);
	}
	else {
		std::cout << this->getName() << " couldn't sign " << form.getName();
		std::cout << " because grade was too low!" << std::endl;
	}
	return ;
}

// Exception class constructor
Bureaucrat::GradeException::GradeException(const std::string& exception) {
	this->_exception = exception;
	return ;
}

// Exception class destructor
Bureaucrat::GradeException::~GradeException(void) throw() {
	return ;
}

// Exception class functions
const char* Bureaucrat::GradeException::what(void) const throw () {
	return (this->_exception.c_str());
}

// Ostream overload
std::ostream& operator<< (std::ostream& out, Bureaucrat& obj) {
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return (out);
}