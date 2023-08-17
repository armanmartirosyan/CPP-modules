#include "Form.hpp"

// Constructors
Form::Form(void) : _name("(default)"),
	_signRequired(150), _executeRequired(150) {
		this->_isSigned = false;
		return ;
}

Form::Form(const std::string& name, int signRequired, int executeRequired) :
	_name(name), _signRequired(signRequired), _executeRequired(executeRequired) {
		if (signRequired < 1 || executeRequired < 1)
			throw GradeException("Form::GradeTooHighException");
		if (signRequired > 150 || executeRequired > 150)
			throw GradeException("Form::GradeTooLowException");
		this->_isSigned = false;
		return ;
}

Form::Form(const Form& rhs) : _name(rhs.getName()),
	_signRequired(rhs.getSignRequired()), _executeRequired(rhs.getExecuteRequired()) {
		this->_isSigned = rhs.getIsSigned();
		return ;
}

// Destructor
Form::~Form(void) {
	return ;
}

// Operations
Form& Form::operator=(const Form& rhs) {
	if (this == &rhs)
		return (*this);
	this->_isSigned = rhs.getIsSigned();
	return (*this);
}

// Getters
std::string	Form::getName(void) const {
	return (this->_name);
}

bool	Form::getIsSigned(void) const {
	return (this->_isSigned);
}

int		Form::getSignRequired(void) const {
	return (this->_signRequired);
}

int		Form::getExecuteRequired(void) const {
	return (this->_executeRequired);
}

// Setters
void	Form::setIsSigned(bool sign) {
	this->_isSigned = sign;
	return ;
}

// Functions
void	Form::beSigned(const Bureaucrat& b) {
	if (this->getIsSigned()) {
		std::cout << "Form is already signed!" << std::endl;
		return ;
	}
	if (b.getGrade() > this->getSignRequired())
		throw GradeException("Form::GradeTooLowException");
	b.signForm(*this);
	return ;
}

// Exception class constructor
Form::GradeException::GradeException(const std::string& exception) {
	this->_exception = exception;
	return ;
}

// Exception class destructor
Form::GradeException::~GradeException(void) throw() {
	return ;
}

// Exception class functions
const char* Form::GradeException::what(void) const throw () {
	return (this->_exception.c_str());
}

// Ostream overload
std::ostream& operator<< (std::ostream& os, const Form& obj) {
	os << "Form name  " << obj.getName() << " Signed " << 
	obj.getIsSigned() << " Grade To Sign " << obj.getSignRequired()
	<< " Grade To Execute " << obj.getExecuteRequired() << std::endl;
	return (os);
}
