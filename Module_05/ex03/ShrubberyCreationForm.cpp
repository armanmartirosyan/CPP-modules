#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(void) :
AForm ("(Shrubbery)", "Shrubbery Creation Form", 145, 137) {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name) : 
AForm(name, "Shrubbery Creation Form", 145, 137) {
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) :
AForm (rhs.getName(), rhs.getType(), rhs.getSignRequired(), rhs.getExecuteRequired()) {
	return ;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	return ;
}

// Operations
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
	if (this == &rhs)
		return (*this);
	this->setIsSigned(rhs.getIsSigned());
	return (*this);
}

// Functions
void	ShrubberyCreationForm::beSigned(const Bureaucrat& b) {
	if (this->getIsSigned()) {
		std::cout << "Form is already signed!" << std::endl;
		return ;
	}
	if (b.getGrade() > this->getSignRequired())
		throw GradeException("ShrubberyCreationForm::GradeTooLowException");
	b.signForm(*this);
	return ;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& b) const {
	if (!this->getIsSigned()) {
		std::cout << this->getName() << " form need to sign." << std::endl;
		return ;
	}
	if (b.getGrade() <= this->getExecuteRequired()){
		std::ofstream	outFile((this->getName() + "_shrubbery").c_str());

		if (!outFile.is_open())
			throw std::runtime_error("Error opening the file.");
		for (size_t i = 0; i < 128; ++i)
			outFile << "ASCII:" << i << " Character: " << static_cast<char>(i) << std::endl;
		outFile.close();
	}
	else
		throw GradeException("ShrubberyCreationForm::GradeTooLowException");
	return ;
}
