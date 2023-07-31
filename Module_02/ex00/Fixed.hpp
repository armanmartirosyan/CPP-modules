#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed&);
		Fixed& operator=(Fixed&);
		~Fixed(void);

		// Functions
		int		getRawBits(void) const;
		void	setRawBits(const int);
	
	private:
		int					_fixed;
		static const int	_frac;
};

#endif
