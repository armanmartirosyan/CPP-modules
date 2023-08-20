#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include <stdexcept>

class Intern {
	public:
		// Constructors
		Intern(void);
		Intern(const Intern&);
		~Intern(void);

		// Operations
		Intern& operator=(const Intern&);

		// Functions
		AForm*	makePresidentialPardonForm(const std::string&)		const;
		AForm*	makeShrubberyCreationForm(const std::string&)		const;
		AForm*	makeRobotomyRequestForm(const std::string&)			const;
		AForm*	makeForm(const std::string&, const std::string&)	const;
};

#endif