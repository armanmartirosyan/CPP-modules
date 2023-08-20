#pragma once
#ifndef AForm_HPP
#define AForm_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		// Constructors
		AForm(void);
		AForm(const std::string&, const std::string&, int, int);
		AForm(const AForm&);
		virtual	~AForm(void);

		// Operations
		AForm& operator=(const AForm&);

		// Getters
		std::string	getName(void)				const;
		std::string	getType(void)				const;
		bool		getIsSigned(void)			const;
		int			getSignRequired(void)		const;
		int			getExecuteRequired(void)	const;

		// Setters	
		void	setIsSigned(bool);

		// Functions
		virtual void	beSigned(const Bureaucrat&) = 0;
		virtual void	execute(const Bureaucrat&)	const = 0;

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
		const std::string	_type;
		bool				_isSigned;
		const int			_signRequired;
		const int			_executeRequired;
};

std::ostream& operator<<(std::ostream&, const AForm&);

#endif