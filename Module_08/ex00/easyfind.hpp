#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

template<typename T>
typename T::iterator	easyFind(T array, int val) {
	typename T::iterator it = std::find(array.begin(), array.end(), val);
	if (it != array.end())
		return (it);
	else
		throw std::runtime_error("No such value");
}

#endif