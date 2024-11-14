
#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

void	wrongAnimal()
{
	std::cout << "Creating WrongAnimal" << std::endl << std::endl;
	WrongAnimal	*wrong[2] = {new WrongAnimal(), new WrongCat()};

	std::cout << std::endl;
	std::cout << "Animal go:" << std::endl;
	for (int i = 0; i < 2; i++)
		wrong[i]->makeSound();
	std::cout << std::endl;
	std::cout << "Animals gone" << std::endl << std::endl;
	for (int i = 0; i < 2; i++)
		delete wrong[i];
}

void	normalAnimal()
{
	std::cout << "Creating Animal, Cat and Dog" << std::endl << std::endl;
	Animal	*zoo[2] = {new Cat(), new Dog()};

	std::cout << std::endl;
	std::cout << "Animal go:" << std::endl;
	for (int i = 0; i < 2; i++)
		zoo[i]->makeSound();
	
	std::cout << std::endl;
	std::cout << "Animals gone" << std::endl << std::endl;
	for (int i = 0; i < 2; i++)
		delete zoo[i];
}

int main()
{
	std::cout << "Starting Polymorphism" << std::endl << std::endl;
	normalAnimal();
	wrongAnimal();
	return (0);
}