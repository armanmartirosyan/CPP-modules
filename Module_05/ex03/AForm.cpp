#include "AForm.hpp"

// Constructors
AForm::AForm(void) : _name("(default)"), _type("(default)"),
	_signRequired(150), _executeRequired(150) {
		this->_isSigned = false;
		return ;
}

AForm::AForm(const std::string& name, const std::string& type, int signRequired, int executeRequired) :
	_name(name), _type(type), _signRequired(signRequired), _executeRequired(executeRequired) {
		if (signRequired < 1 || executeRequired < 1)
			throw GradeException("AForm::GradeTooHighException");
		if (signRequired > 150 || executeRequired > 150)
			throw GradeException("AForm::GradeTooLowException");
		this->_isSigned = false;
		return ;
}

AForm::AForm(const AForm& rhs) : _name(rhs.getName()),
	_signRequired(rhs.getSignRequired()), _executeRequired(rhs.getExecuteRequired()) {
		this->_isSigned = rhs.getIsSigned();
		return ;
}

// Destructor
AForm::~AForm(void) {
	return ;
}

// Operations
AForm& AForm::operator=(const AForm& rhs) {
	if (this == &rhs)
		return (*this);
	this->_isSigned = rhs.getIsSigned();
	return (*this);
}

// Getters
std::string	AForm::getName(void) const {
	return (this->_name);
}

std::string AForm::getType(void) const {
	return (this->_type);
}

bool	AForm::getIsSigned(void) const {
	return (this->_isSigned);
}

int		AForm::getSignRequired(void) const {
	return (this->_signRequired);
}

int		AForm::getExecuteRequired(void) const {
	return (this->_executeRequired);
}

// Setters
void	AForm::setIsSigned(bool sign) {
	this->_isSigned = sign;
	return ;
}

// Exception class constructor
AForm::GradeException::GradeException(const std::string& exception) {
	this->_exception = exception;
	return ;
}

// Exception class destructor
AForm::GradeException::~GradeException(void) throw() {
	return ;
}

// Exception class functions
const char* AForm::GradeException::what(void) const throw () {
	return (this->_exception.c_str());
}

// Ostream overload
std::ostream& operator<< (std::ostream& os, const AForm& obj) {
	os << "AForm name  " << obj.getName() << " Signed " << 
	obj.getIsSigned() << " Grade To Sign " << obj.getSignRequired()
	<< " Grade To Execute " << obj.getExecuteRequired() << std::endl;
	return (os);
}
