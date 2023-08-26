#pragma once
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>

struct Data {
	std::string	name;
	int			data;
};


class Serializer {
	public:
		static uintptr_t serialize(Data*);
		static Data* deserialize(uintptr_t);
	private:
		// Constructors
		Serializer(void);
		Serializer(const Serializer&);
		~Serializer(void);

		// Operations
		Serializer&	operator=(const Serializer&);

};

#endif