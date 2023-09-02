#include <iostream>
#include "iter.hpp"

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Iterating through intArray: ";
	iter(intArray, intArrayLength, printValue<const int>);
	std::cout << std::endl;

	const double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	const size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

	std::cout << "Iterating through doubleArray: ";
	iter(doubleArray, doubleArrayLength, printValue<double>);
	std::cout << std::endl;

	std::string stringArray[] = {"a", "b", "c", "d", "e"};
	size_t stringArrayLength = sizeof(stringArray) / sizeof(stringArray[0]);

	std::cout << "Iterating through stringArray: ";
	iter(stringArray, stringArrayLength, printValue<std::string>);
	std::cout << std::endl;


  return 0;
}