#include "Serializer.hpp"
#include <typeinfo>

int main (void) {
	Data *dataPtr = new Data;

	dataPtr->name = "John";
	dataPtr->data = 42;

	std::cout << "Type: " << typeid(dataPtr).name() << std::endl;
	std::cout << "Name: " << dataPtr->name << std::endl;
	std::cout << "Data: " << dataPtr->data << std::endl;

	uintptr_t uintPtr = Serializer::serialize(dataPtr);

	std::cout << "uintptr_t: " << uintPtr << std::endl;

	Data *test = Serializer::deserialize(uintPtr);

	std::cout << "Type: " << typeid(test).name() << std::endl;
	std::cout << "Name: " << test->name << std::endl;
	std::cout << "Data: " << test->data << std::endl;

	return (0);
}