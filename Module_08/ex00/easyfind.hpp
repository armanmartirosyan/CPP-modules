#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <stdexcept>
# include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int val) {
	typename T::iterator it = std::find(container.begin(), container.end(), val);
	if (it == container.end())
		throw std::logic_error("Value is not found.");
	return (it);
}

#endif