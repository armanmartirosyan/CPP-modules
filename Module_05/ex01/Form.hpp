#pragma once
#ifndef FORM_HPP
#define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		// Constructors
		Form(void);
		Form(const std::string&, int, int);
		Form(const Form&);
		~Form(void);

		// Operations
		Form& operator=(const Form&);

		// Getters
		std::string	getName(void)				const;
		bool		getIsSigned(void)			const;
		int			getSignRequired(void)		const;
		int			getExecuteRequired(void)	const;

		// Setters	
		void	setIsSigned(bool);

		// Functions
		void	beSigned(const Bureaucrat&);

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
		const std::string	_name;
		bool				_isSigned;
		const int			_signRequired;
		const int			_executeRequired;
};

std::ostream& operator<<(std::ostream&, const Form&);

#endif