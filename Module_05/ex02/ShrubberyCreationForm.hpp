#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

# include "Bureaucrat.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {
	public:
		// Constructors
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string&);
		ShrubberyCreationForm(const ShrubberyCreationForm&);
		~ShrubberyCreationForm(void);

		// Operations
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);

		// Functions
		void	beSigned(const Bureaucrat&);
		void	execute(const Bureaucrat&)	const;
};

#endif