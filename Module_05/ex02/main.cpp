#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	AForm *president = 0;
	AForm *shrubbery = 0;
	AForm *robotomy = 0;
	Bureaucrat John(30, "John");
	try
	{
		std::cout << "----------------------------------------------------" << std::endl;
		shrubbery = new ShrubberyCreationForm("Shrubbery");
		std::cout << *shrubbery;
		John.signForm(*shrubbery);
		John.executeForm(*shrubbery);
		shrubbery->execute(John);
		std::cout << *shrubbery;
		std::cout << "----------------------------------------------------" << std::endl;

		std::cout << "----------------------------------------------------" << std::endl;
		robotomy = new RobotomyRequestForm("Robotomy");
		std::cout << *robotomy;
		John.signForm(*robotomy);
		John.executeForm(*robotomy);
		std::cout << *robotomy;
		std::cout << "----------------------------------------------------" << std::endl;

		president = new PresidentialPardonForm();
		std::cout << "----------------------------------------------------" << std::endl;
		std::cout << *president;
		president->beSigned(John);
		John.executeForm(*president);
		std::cout << *president;
		std::cout << "----------------------------------------------------" << std::endl;
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}