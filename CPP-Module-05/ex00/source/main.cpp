
#include "../include/Bureaucrat.hpp"

void	normalBureaucrat()
{
	try
	{
		Bureaucrat bob("Bob", 2);
		std::cout << bob;

		bob.demote();
		std::cout << bob;

		bob.promote();
		std::cout << bob;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	gradeTooHigh()
{
	try
	{
		Bureaucrat	bob("Bob", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	gradeTooLow()
{
	try
	{
		Bureaucrat	bob("Bob", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	promotion()
{
	try
	{
		Bureaucrat	bob("Bob", 1);
		bob.promote(); 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	demotion()
{
	try
	{
		Bureaucrat	bob("Bob", 150);
		bob.demote(); 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
/**
 * @brief Entry point of the program.
 *
 * This function demonstrates various operations related to a Bureaucrat class.
 * It includes the following operations:
 * - normalBureaucrat: Creates a Bureaucrat with normal grade.
 * - gradeTooHigh: Attempts to create a Bureaucrat with a grade that is too high.
 * - gradeTooLow: Attempts to create a Bureaucrat with a grade that is too low.
 * - promotion: Tries to promote a Bureaucrat with the max grade.
 * - demotion: Tries to demote a Bureaucrat with the min grade.
 *
 * @return int Returns 0 upon successful execution.
 */
int	main(void)
{
	normalBureaucrat();
	gradeTooHigh();
	gradeTooLow();
	promotion();
	demotion();
	return(0);
}