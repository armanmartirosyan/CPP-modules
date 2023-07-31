#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed&);
		Fixed(const int);
		Fixed(const float);
		~Fixed(void);

		// Operations
		Fixed&	operator=(const Fixed&);
		bool	operator<(const Fixed&) 	const;
		bool	operator<=(const Fixed&)	const;
		bool	operator>(const Fixed&) 	const;
		bool	operator>=(const Fixed&)	const;
		bool	operator==(const Fixed&)	const;
		bool	operator!=(const Fixed&)	const;
		Fixed	operator+(const Fixed&) 	const;
		Fixed	operator*(const Fixed&) 	const;
		Fixed	operator-(const Fixed&) 	const;
		Fixed	operator/(const Fixed&) 	const;
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		// Functions
		int		getRawBits(void) 		 	const;
		void	setRawBits(const int);
		float	toFloat(void) 			 	const;
		int		toInt(void) 			 	const;
		static	Fixed& min(Fixed&, Fixed&);
		static	Fixed& max(Fixed&, Fixed&);
		static const Fixed& min(const Fixed&, const Fixed&);
		static const Fixed& max(const Fixed&, const Fixed&);
	
	private:
		int					_fixed;
		static const int	_frac;
};

std::ostream&	operator<<(std::ostream&, const Fixed&);

#endif
