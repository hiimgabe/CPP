
#include "../include/AAnimal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/Brain.hpp"

#define RESET "\033[0m"
#define RED "\033[38;5;196m"
#define GREEN "\033[38;5;47m"
#define YELLOW "\033[38;5;226m"

void	clearScreen(void)
{
	std::cout << "\033c";
}

void	pressEnter(void)
{
	std::cout << "\nPress Enter to continue. . ." << std::endl;
	std::cin.get();
}

void	correctBrainOperations(void)
{
	Cat*	cat1 = new Cat();
	Dog*	dog1 = new Dog();

	std::cout << std::endl;
	std::cout << YELLOW << "\n=== Setting dog and cat ideas ===\n" << std::endl;
	dog1->getBrain()->setIdea("no thoughts just exist", 0);
	dog1->getBrain()->setIdea("*hungry*", 1);
	cat1->getBrain()->setIdea("damn this human is dumb", 0);
	cat1->getBrain()->setIdea("SERVE ME HUMAN", 1);

	std::cout << std::endl;
	std::cout << GREEN << "\n=== Printing dog ideas ===\n" << RESET << std::endl << std::endl;
	dog1->getBrain()->printIdeas();
	std::cout << std::endl;
	std::cout << GREEN << "\n=== Printing cat ideas ===\n" << RESET << std::endl << std::endl;
	cat1->getBrain()->printIdeas();
	std::cout << std::endl;
	delete dog1;
	delete cat1;
	pressEnter();
}

void	normalAnimal()
{
	std::cout << YELLOW << "\n=== Creating Animal, Cat and Dog ===\n" << RESET << std::endl << std::endl;
	AAnimal	*zoo[2] = {new Cat(), new Dog()};

	std::cout << std::endl;
	std::cout << GREEN << "\n=== Animal sounds ===\n" << RESET << std::endl;
	for (int i = 0; i < 2; i++)
		zoo[i]->makeSound();
	std::cout << std::endl;
	for (int i = 0; i < 2; i++)
		delete zoo[i];
	pressEnter();
}

int main()
{
	clearScreen();
	std::cout << "Starting brain operations" << std::endl << std::endl;
	
	//AAnimal *instantiateTest = new AAnimal();

	std::cout << YELLOW << "\n=== Basic Test ===\n" << RESET << std::endl;
	Cat basic;
	{
		Cat tmp = basic;
	}
	Dog basic2;
	{
		Dog tmp = basic2;
	}
	normalAnimal();
	correctBrainOperations();
	return (0);
}