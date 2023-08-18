#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include "Bureaucrat.hpp"
# include <ctime>

class RobotomyRequestForm : public AForm {
	public:
		// Constructors
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string&);
		RobotomyRequestForm(const RobotomyRequestForm&);
		~RobotomyRequestForm(void);

		// Operations
		RobotomyRequestForm& operator=(const RobotomyRequestForm&);

		// Functions
		void	beSigned(const Bureaucrat&);
		void	execute(const Bureaucrat&)	const;
};

#endif