
#include "../include/AAnimal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/Brain.hpp"

void	correctBrainOperations(void)
{
	Cat*	cat1 = new Cat();
	Dog*	dog1 = new Dog();

	std::cout << std::endl;
	std::cout << "Setting dog and cat ideas" << std::endl;
	dog1->getBrain()->setIdea("no thoughts just exist", 0);
	dog1->getBrain()->setIdea("*hungry*", 1);
	cat1->getBrain()->setIdea("damn this human is dumb", 0);
	cat1->getBrain()->setIdea("SERVE ME HUMAN", 1);

	std::cout << std::endl;
	std::cout << "Printing dog ideas" << std::endl << std::endl;
	dog1->getBrain()->printIdeas();
	std::cout << std::endl;
	std::cout << "Printing cat ideas" << std::endl << std::endl;
	cat1->getBrain()->printIdeas();

	Cat	dog2 = *cat1;
	dog2.getBrain()->printIdeas();

	delete dog1;
	delete cat1;
}

void	normalAnimal()
{
	std::cout << "Creating Animal, Cat and Dog" << std::endl << std::endl;
	AAnimal	*zoo[2] = {new Cat(), new Dog()};

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
	std::cout << "Starting brain operations" << std::endl << std::endl;
	
	//Dog basic;
	//Dog test(basic);

	Cat basic;
	{
		Cat tmp = basic;
	}
	Dog basic2;
	{
		Dog tmp = basic2;
	}

	//normalAnimal();
	//correctBrainOperations();
	return (0);
}