
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

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

void	shrubberyTest()
{
	AForm	*shrubbery = new ShrubberyCreationForm("Home");
	Bureaucrat	bob("Bob", 146);

	std::cout << "\n==== Using the following classes ====\n" << std::endl;
	std::cout << *shrubbery << bob;
	std::cout << "\n==== Trying to sign form without necessary grade ====\n" << std::endl;
	try
	{
		shrubbery->beSigned(bob);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n==== Trying to sign form with minimun grade ====\n" << std::endl;
	bob.promote();
	try
	{
		shrubbery->beSigned(bob);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n==== Trying to execute form without necessary grade ====\n" << std::endl;
	try
	{
		bob.executeForm(*shrubbery);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	for (int i = 0; i < 9; i++)
		bob.promote();
	std::cout << "\n==== Bureaucrat after stats after promotion ====\n" << std::endl;
	std::cout << bob;
	std::cout << "\n==== Trying to execute form with minimun grade ====\n" << std::endl;
	try
	{
		bob.executeForm(*shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete shrubbery;
}

void	robotomizedTest()
{
	AForm	*robotomy = new RobotomyRequestForm("Neil");
	Bureaucrat	bob("Bob", 73);

	std::cout << "\n==== Using the following classes ====\n" << std::endl;
	std::cout << *robotomy << bob;
	std::cout << "\n==== Trying to sign form without necessary grade ====\n" << std::endl;
	try
	{
		robotomy->beSigned(bob);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n==== Trying to sign form with minimun grade ====\n" << std::endl;
	bob.promote();
	try
	{
		robotomy->beSigned(bob);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n==== Trying to execute form without necessary grade ====\n" << std::endl;
	try
	{
		bob.executeForm(*robotomy);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	for (int i = 0; i < 28; i++)
		bob.promote();
	std::cout << "\n==== Bureaucrat after stats after promotion ====\n" << std::endl;
	std::cout << bob;
	std::cout << "\n==== Trying to execute form with minimun grade ====\n" << std::endl;
	try
	{
		for (int i = 0; i < 20; i++)
			bob.executeForm(*robotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	delete robotomy;
}

void	presidentialTest()
{
	AForm	*presidential = new PresidentialPardonForm("Bob");
	Bureaucrat	bob("Bob", 26);

	std::cout << "\n==== Using the following classes ====\n" << std::endl;
	std::cout << *presidential << bob;
	std::cout << "\n==== Trying to sign form without necessary grade ====\n" << std::endl;
	try
	{
		presidential->beSigned(bob);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n==== Trying to sign form with minimun grade ====\n" << std::endl;
	bob.promote();
	try
	{
		presidential->beSigned(bob);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\n==== Trying to execute form without necessary grade ====\n" << std::endl;
	try
	{
		bob.executeForm(*presidential);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	for (int i = 0; i < 20; i++)
		bob.promote();
	std::cout << "\n==== Bureaucrat after stats after promotion ====\n" << std::endl;
	std::cout << bob;
	std::cout << "\n==== Trying to execute form with minimun grade ====\n" << std::endl;
	try
	{
		bob.executeForm(*presidential);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete presidential;
}

int	main(void)
{
	clearScreen();
	shrubberyTest();
	pressEnter();
	clearScreen();
	robotomizedTest();
	pressEnter();
	clearScreen();
	presidentialTest();

	return(0);
}