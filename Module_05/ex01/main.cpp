#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat John(25, "John");
		Bureaucrat Dwayne(40, "Dwayne");

		Form form30("John's form", 30, 30);
		Form clone(form30);

		John.signForm(form30);
		form30.beSigned(Dwayne);

		std::cout << form30;
		Dwayne.signForm(clone);
		clone.beSigned(Dwayne);
		std::cout << form30;

	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}