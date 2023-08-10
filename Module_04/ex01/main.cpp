#include <iostream>
#include <sstream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define ZOOCOUNT 4

int main() {
	Animal* animals[ZOOCOUNT];

	for (size_t i = 0; i < ZOOCOUNT; i++) {
        if (i < 2) {
            std::cout<<"------------------------DOG------------------------"<<std::endl;
            animals[i] = new Dog();
        } else {
            std::cout<<"------------------------CAT------------------------"<<std::endl;
            animals[i] = new Cat();
        }
    }


	std::cout << std::endl;
	std::cout << "-----------------------TEST------------------------" << std::endl;
	Cat myCat;
	std::cout << "---------------------------------------------------" << std::endl;
	Cat notMyCat;
	std::cout << "---------------------------------------------------" << std::endl;
	
	Brain b;
	std::cout << "---------------------------------------------------" << std::endl;

	b.setIdea(1, "Hello World");
	b.setIdea(44,"Something");

	myCat.setCatBrain(b);
	std::cout << "---------------------------------------------------" << std::endl;
	b.setIdea(1,"Goodbye");
	std::cout << myCat.getCatIdea(1) << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << myCat.getCatIdea(44) << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << myCat.getCatIdea(35) << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;


	std::stringstream ss;

	for (size_t i = 0; i < 120; ++i) {
		ss << i;
		myCat.setCatIdea(i,"I have idea - " + ss.str());
		ss.str("");
	}
	notMyCat = myCat;
	std::cout << "---------------------------------------------------" << std::endl;

	std::cout << notMyCat.getCatIdea(26) << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << notMyCat.getCatIdea(101) << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << notMyCat.getCatIdea(1) << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << notMyCat.getCatIdea(105) << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;


	for (size_t i = 0; i < ZOOCOUNT; i++) {
		animals[i]->makeSound();
		std::cout << "---------------------------------------------------" << std::endl;
		delete animals[i];
		std::cout << "---------------------------------------------------" << std::endl;	
	}
	return (0);
}
