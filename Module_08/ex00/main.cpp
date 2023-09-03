#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

# define MAX_VAL 25000

int main (void) {
	std::vector<int>			myVector;
	std::vector<int>::iterator	itVector;
	for (size_t i = 0; i < MAX_VAL; i++)
		myVector.push_back(i);
	try {
		itVector = easyfind(myVector, 16241);
		std::cout << (*itVector) << std::endl;
	} catch (const std::logic_error& e) {
		std::cerr << e.what() << std::endl;
	}

	std::list<int>				myList;
	std::list<int>::iterator	itList;
	for (size_t i = 0; i < MAX_VAL; i++)
		myList.push_back(i);
	try {
		itList = easyfind(myList, 15543);
		std::cout << (*itList) << std::endl;
	} catch (const std::logic_error& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
