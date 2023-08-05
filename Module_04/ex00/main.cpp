#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main() {
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound! 
		j->makeSound();
		meta->makeSound();
		
		delete meta;
		delete j;
		delete i;
	}
std::cout << "----------------------------------------------------" << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* j = new WrongDog();
		const WrongAnimal* i = new WrongCat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound! 
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	return (0);
}