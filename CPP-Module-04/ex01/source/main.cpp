
#include "../include/Animal.hpp"
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
	Cat	*cat1 = new Cat();
	Dog	*dog1 = new Dog();

	std::cout << YELLOW <<"\n=== Setting Cat ideas ===\n" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
		cat1->getBrain()->setIdea("meow",i);
	std::cout << GREEN <<"\n=== Printing Cat ideas ===\n" << RESET << std::endl;
	cat1->getBrain()->printIdeas();
	pressEnter();
	std::cout << YELLOW << "\n=== Setting Dog ideas ===\n" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
		dog1->getBrain()->setIdea("bark",i);
	std::cout << GREEN << "\n=== Printing Dog ideas ===\n" << RESET << std::endl;
	dog1->getBrain()->printIdeas();
	std::cout << std::endl;
	delete cat1;
	delete dog1;
	pressEnter();
}

void	wrongBrainOpreations(void)
{
	Cat	*cat1 = new Cat();
	Dog	*dog1 = new Dog();
	int	below = -1;
	int	above = 150;

	std::cout << YELLOW << "\n=== Trying to set ideas at indexes: " << below << " and " << above << " ===\n" << RESET << std::endl;
	std::cout << GREEN << "\n=== Setting Cat ideas out of range ===\n" << RESET << std::endl;
	try
	{
		cat1->getBrain()->setIdea("OoOoOoOoOoOoOoOO", below);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		cat1->getBrain()->setIdea("OoOoOoOoOoOoOoOO", above);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	pressEnter();
	std::cout << GREEN << "\n=== Setting Dog ideas out of range ===\n" << RESET << std::endl;
	try
	{
		dog1->getBrain()->setIdea("OoOoOoOoOoOoOoOO", below);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		dog1->getBrain()->setIdea("OoOoOoOoOoOoOoOO", above);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete cat1;
	delete dog1;
	pressEnter();
}

void	deepCopyTest(void)
{
	std::cout << GREEN << "\n=== Cat deep copy test ===\n" << RESET << std::endl;
	Cat basicCat;
	basicCat.getBrain()->setIdea("I am a cat", 0);
	std::cout << YELLOW << "\n=== Printing BasicCat ideas before tmp being deleted inside scope ===\n" << RESET << std::endl;
	basicCat.getBrain()->printIdeas();
	std::cout << std::endl;
	{
		Cat tmp = basicCat;
		std::cout << GREEN << "\n=== Printing tmp ideas after assign ===\n" << RESET << std::endl;
		tmp.getBrain()->printIdeas();
		std::cout << std::endl;
	}
	std::cout << GREEN << "\n=== Printing BasicCat ideas after tmp being deleted inside scope ===\n" << RESET << std::endl;
	basicCat.getBrain()->printIdeas();
	pressEnter();
	std::cout << GREEN << "\n=== Dog deep copy test ===\n" << RESET << std::endl;
	Dog basicDog;
	basicDog.getBrain()->setIdea("I am a dog", 0);
	std::cout << YELLOW << "\n=== Printing BasicDog ideas before tmp being deleted inside scope ===\n" << RESET << std::endl;
	basicDog.getBrain()->printIdeas();
	std::cout << std::endl;
	{
		Dog tmp = basicDog;
		std::cout << GREEN << "\n=== Printing tmp ideas after assign ===\n" << RESET << std::endl;
		tmp.getBrain()->printIdeas();
		std::cout << std::endl;
	}
	std::cout << GREEN << "\n=== Printing BasicDog ideas after tmp being deleted inside scope ===\n" << RESET << std::endl;
	basicDog.getBrain()->printIdeas();
	pressEnter();
}

void	deepCopyTest2(void)
{
	Cat	cat1;
	Dog	dog1;

	std::cout << GREEN << "\n=== Cat deep copy with ideas in Brain test ===\n" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
		cat1.getBrain()->setIdea("meow", i);
	std::cout << YELLOW << "\n=== Cat Brain before tmpCat delete inside scope ===\n" << RESET << std::endl;
	cat1.getBrain()->printIdeas();
	std::cout << std::endl;
	{
		Cat tmpCat = cat1;
		std::cout << GREEN << "\n=== tmpCat Brain ===\n" << RESET << std::endl;
		tmpCat.getBrain()->printIdeas();
		std::cout << std::endl;
	}
	std::cout << GREEN << "\n=== Cat Brain after tmpCat delete inside scope ===\n" << RESET << std::endl;
	cat1.getBrain()->printIdeas();
	pressEnter();
	std::cout << GREEN << "\n=== Dog deep copy with ideas in Brain test ===\n" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
		dog1.getBrain()->setIdea("bork", i);
	std::cout << YELLOW << "\n=== Dog Brain before tmpDog delete inside scope ===\n" << RESET << std::endl;
	dog1.getBrain()->printIdeas();
	std::cout << std::endl;
	{
		Dog tmpDog = dog1;
		std::cout << GREEN << "\n=== tmpDog Brain ===\n" << RESET << std::endl;
		tmpDog.getBrain()->printIdeas();
		std::cout << std::endl;
	}
	std::cout << GREEN << "\n=== Dog Brain after tmpDog delete inside scope ===\n" << RESET << std::endl;
	dog1.getBrain()->printIdeas();
	std::cout << std::endl;
	pressEnter();
}

void	subjectBasicTest()
{
	std::cout << GREEN << "\n=== Subject Test ===\n" << RESET << std::endl;
	Dog dog;
	{
		Dog tmp = dog;
	}
	Cat	cat;
	{
		Cat tmp = cat;
	}
}

int main()
{
	clearScreen();
	subjectBasicTest(); // Test OK OK
	deepCopyTest(); // Test OK OK
	deepCopyTest2(); // Test OK OK
	correctBrainOperations(); // Test OK OK
	wrongBrainOpreations(); // Test OK OK
	return (0);
}