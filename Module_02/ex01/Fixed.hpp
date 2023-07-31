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
		Fixed& operator=(const Fixed&);
		~Fixed(void);

		// Functions
		int		getRawBits(void) const;
		void	setRawBits(const int);
		float	toFloat(void) const;
		int		toInt(void) const;
	
	private:
		int					_fixed;
		static const int	_frac;
};

std::ostream&	operator<<(std::ostream&, const Fixed&);

#endif
