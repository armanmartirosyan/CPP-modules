#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
	public:
		// Constructors
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string&);
		PresidentialPardonForm(const PresidentialPardonForm&);
		~PresidentialPardonForm(void);

		// Operations
		PresidentialPardonForm& operator=(const PresidentialPardonForm&);

		// Functions
		void	beSigned(const Bureaucrat&);
		void	execute(const Bureaucrat&)	const;
};

#endif