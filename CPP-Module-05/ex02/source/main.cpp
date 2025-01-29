/**
 * @brief Main file for testing Bureaucrat and Form classes.
 * 
 * It tests the functionality of signing and executing different types of forms by a Bureaucrat.
 * 
 * The following forms are tested:
 * - ShrubberyCreationForm
 * - RobotomyRequestForm
 * - PresidentialPardonForm
 * 
 * The tests include:
 * - Signing forms with insufficient and sufficient grades.
 * - Executing forms with insufficient and sufficient grades.
 * - Promoting the Bureaucrat to meet the required grades.
 * 
 */
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

void	clearScreen(void)
{
	std::cout << "\033c";
}

void	pressEnter(void)
{
	std::cout << "\nPress Enter to continue. . ." << std::endl;
	std::cin.get();
}
/**
 * @brief Tests the ShrubberyCreationForm with a Bureaucrat.
 * 
 * This function creates a ShrubberyCreationForm and a Bureaucrat with a low grade.
 * It attempts to sign and execute the form with insufficient and sufficient grades.
 * The Bureaucrat is promoted to meet the required grades for signing and executing the form.
 */
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
	std::cout << "\n==== Bureaucrat stats after promotion ====" << std::endl;
	bob.promote(); // Grade 145
	std::cout << bob;
	std::cout << "\n==== Trying to sign form with minimun grade ====\n" << std::endl;
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
	for (int i = 0; i < 8; i++)
		bob.promote();
	std::cout << "\n==== Bureaucrat stats after promotion ====" << std::endl;
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
/**
 * @brief Tests the RobotomyRequestForm with a Bureaucrat.
 * 
 * This function creates a RobotomyRequestForm and a Bureaucrat with a low grade.
 * It attempts to sign and execute the form with insufficient and sufficient grades.
 * The Bureaucrat is promoted to meet the required grades for signing and executing the form.
 */
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
	std::cout << "\n==== Bureaucrat stats after promotion ====" << std::endl;
	bob.promote();
	std::cout << bob;
	std::cout << "\n==== Trying to sign form with minimun grade ====\n" << std::endl;
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
	for (int i = 0; i < 27; i++)
		bob.promote();
	std::cout << "\n==== Bureaucrat stats after promotion ====" << std::endl;
	std::cout << bob;
	std::cout << "\n==== Trying to execute form with minimun grade ====\n" << std::endl;
	try
	{
		for (int i = 0; i < 20; i++)
		{
			bob.executeForm(*robotomy);
			std::cout << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	delete robotomy;
}
/**
 * @brief Tests the PresidentialPardonForm with a Bureaucrat.
 * 
 * This function creates a PresidentialPardonForm and a Bureaucrat with a low grade.
 * It attempts to sign and execute the form with insufficient and sufficient grades.
 * The Bureaucrat is promoted to meet the required grades for signing and executing the form.
 */
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
	std::cout << "\n==== Bureaucrat stats after promotion ====" << std::endl;
	bob.promote();
	std::cout << bob;
	std::cout << "\n==== Trying to sign form with minimun grade ====\n" << std::endl;
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
	std::cout << "\n==== Bureaucrat stats after promotion ====" << std::endl;
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