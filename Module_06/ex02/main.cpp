#include <iostream>
#include <cstdlib>
#include <ctime> 
#include "Base.hpp"

Base*	generate(void) {
	std::srand(std::time(0));

	switch (std::rand() % 3)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			break;
	}
	return (new Base());
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "p: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "p: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "p: C" << std::endl;
	return  ;
}

void	identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "p: A" << std::endl;
	} catch (const std::exception& e) {
		try {
			(void)dynamic_cast<B&>(p);
			std::cout << "p: B" << std::endl;
		} catch (const std::exception& e) {
			std::cout << "p: C" << std::endl;
		}
	}
	return ;
}

int main() {
	Base* a = generate();

	std::cout << "----------Random---------" << std::endl;
	identify(a);
	identify(*a);

	{
		Base* a = new A();
		std::cout << "------------A------------" << std::endl;
		identify(a);
		identify(*a);
	}
	{
		Base* b = new B();
		std::cout << "------------B------------" << std::endl;
		identify(b);
		identify(*b);
	}
	{
		Base* c = new C();
		std::cout << "------------C------------" << std::endl;
		identify(c);
		identify(*c);
	}
	return (0);
}