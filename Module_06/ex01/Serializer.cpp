#include "Serializer.hpp"

// Constructors
Serializer::Serializer(void) {
	return ;
}

Serializer::Serializer(const Serializer& rhs) {
	(void) rhs;
	return ;
}

// Destructor
Serializer::~Serializer(void) {
	return ;
}

// Operations
Serializer& Serializer::operator= (const Serializer& rhs) {
	(void) rhs;
	return (*this);
}

// Functions
uintptr_t Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}