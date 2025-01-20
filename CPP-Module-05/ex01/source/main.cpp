
#include "../include/Bureaucrat.hpp"

void	clearScreen(void)
{
	std::cout << "\033c";
}

void	pressEnter(void)
{
	std::cout << "\nPress Enter to continue. . ." << std::endl;
	std::cin.get();
}

void	formTest(void)
{
	std::string	formName = "Form Test";
	
	std::cout << "==== 1st Test =====\n" << std::endl;
	std::cout << "\n==== Creating form with signGrade < 0 ====\n" << std::endl;
	try
	{
		Form gradeTooHigh(formName, 0, 2);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\n==== Creating form with execGrade < 0 ====\n" << std::endl;
	try
	{
		Form gradeTooHigh(formName, 2, 0);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\n==== Creating form with signGrade > 150 ====\n" << std::endl;
	try
	{
		Form gradeTooHigh(formName, 151, 2);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\n==== Creating form with execGrade > 150 ====\n" << std::endl;
	try
	{
		Form gradeTooHigh(formName, 2, 151);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\n==== Correctly creating Form. ====\n" << std::endl;
	try
	{
		Form	correct(formName, 5, 1);
		std::cout << correct << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	signFormTest(void)
{
	std::string	formName = "TestForm";
	Bureaucrat bob("Bob", 43);
	Form	testForm(formName, 42, 1);

	std::cout << "==== 2nd Test ====\n" << std::endl;
	std::cout << bob << std::endl;
	std::cout << testForm << std::endl;

	std::cout << "==== Bob tries to sign a Form he shouldn't be able to ====\n" << std::endl;
	try
	{
		bob.signForm(testForm);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	bob.promote();
	std::cout << "\n==== Bob tries to sign a Form he should be able to ====\n" << std::endl;
	try
	{
		bob.signForm(testForm);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	clearScreen();
	formTest();
	signFormTest();
	return(0);
}