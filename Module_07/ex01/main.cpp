#include <iostream>
#include "iter.hpp"

	// int intArray[] = {1, 2, 3, 4, 5};
	// size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

	// std::cout << "Iterating through intArray: ";
	// iter(intArray, intArrayLength, printValue<int>);
	// std::cout << std::endl;

	// const double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	// const size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

	// std::cout << "Iterating through doubleArray: ";
	// iter(doubleArray, doubleArrayLength, printValue<double>);
	// std::cout << std::endl;

	// std::string stringArray[] = {"apple", "banana", "cherry", "date", "elderberry"};
	// size_t stringArrayLength = sizeof(stringArray) / sizeof(stringArray[0]);

	// std::cout << "Iterating through stringArray: ";
	// iter(stringArray, stringArrayLength, printValue<std::string>);
	// std::cout << std::endl;

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}