#pragma once
#ifndef ARRAY_TPP
# define ARRAY_TPP

// Construtors
template<typename T>
Array<T>::Array(void) {
	this->_size = 0;
	this->_data = NULL;
	return ;
}

template<typename T>
Array<T>::Array(unsigned int i) {
	this->_data = new T[i];
	this->_size = i;
	return ;
}

template<typename T>
Array<T>::Array(const Array& rhs) {
	this->_size = rhs._size;
	this->_data = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_data[i] = rhs._data[i];
	return ;
}

// Destructor
template <typename T>
Array<T>::~Array(void) {
	delete [] this->_data;
}

// Operations
template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs) {
	if (this == &rhs)
		return (*this);
	delete [] this->_data;
	this->_size = rhs._size;
	this->_data = new T[this->_size];
	for (unsigned int i = 0; i < this->size; i++)
		this->_data[i] = rhs._data[i];
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](unsigned int i) {
	if (i < this->_size)
		return (this->_data[i]);
	throw	std::out_of_range("Index out of range");
}

// Functions
template <typename T>
unsigned int Array<T>::size(void) const {
	return (this->_size);
}
#endif
