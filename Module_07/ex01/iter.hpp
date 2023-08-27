#pragma once
#ifndef ITER_HPP
# define ITER_HPP

template <typename T, typename Func>
void iter(T* array, size_t length, Func function) {
	for (size_t i = 0; i < length; ++i) {
		function(array[i]);
	}
}


// template <typename T>
// void iter(T* array, size_t length, void (*func)(T const &)) {
// 	for (size_t i = 0; i < length; ++i) {
// 		(*func)(array[i]);
// 	}
// }

// template <typename T, typename Func>
// void iter(const T* array, const size_t length, Func function) {
// 	for (size_t i = 0; i < length; ++i) {
// 		function(array[i]);
// 	}
// }

template <typename T>
void printValue(const T& value) {
	std::cout << value << " ";
}

#endif