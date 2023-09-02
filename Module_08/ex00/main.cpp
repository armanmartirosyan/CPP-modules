#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main (void) {
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int>myVector (array, array + 10);

	std::cout << *(easyFind(myVector, 4)) << std::endl;
	return (0);
}
