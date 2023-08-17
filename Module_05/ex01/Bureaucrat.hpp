#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat {
	public:
		// Constructors
		Bureaucrat(void);
		Bureaucrat(int, const std::string&);
		Bureaucrat(const Bureaucrat&);
		~Bureaucrat(void);

		// Operations
		Bureaucrat&	operator=(const Bureaucrat&);
		Bureaucrat&	operator++(void);
		Bureaucrat	operator++(int);
		Bureaucrat&	operator--(void);
		Bureaucrat	operator--(int);

		// Getters
		std::string		getName(void)	const;
		int				getGrade(void)	const;

		// Setters
		void	setName(const std::string&);
		void	setGrade(int);

		// Functions
		void	signForm(Form&) const;

		// Exception class
		class GradeException : public std::exception
		{
			public:
			// Constructors
				GradeException(const std::string&);
				~GradeException(void) throw();

			// Functions
				virtual const char* what(void) const throw ();
			private:
				std::string	_exception;
		};		
	private:
		std::string	_name;
		int			_grade;
};

std::ostream&	operator<<(std::ostream&, Bureaucrat&);
#endif