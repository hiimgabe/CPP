
#include "../include/Span.hpp"

void	clearScreen(void)
{
	std::cout << "\033c";
}

void	pressEnter(void)
{
	std::cout << "\nPress Enter to continue. . ." << std::endl;
	std::cin.get();
}

void	subjectTest(void)
{
	Span	sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	myTest(void)
{
	Span	test = Span(100001);

	try
	{
		for (int i = 0; i < 100001; i++)
			test.addNumber(i);
		std::cout << "Shortest span : " << test.shortestSpan() << std::endl;
		std::cout << "Longest span : " << test.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void	secondTest(void)
{
	Span	test = Span(5);
	Span	notEnough = Span(1);

	try
	{
		for (int i = 0; i < 6; i++)
			test.addNumber(i);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		notEnough.shortestSpan();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		notEnough.longestSpan();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	fill()
{
	Span	fillT = Span(10000);

	try
	{
		fillT.fill();
		std::cout << "Max number : " << fillT.max() << std::endl;
		std::cout << "Min number : " << fillT.min() << std::endl;
		std::cout << "Shortest span	: " << fillT.shortestSpan() << std::endl;
		std::cout << "Longest span	: " << fillT.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main(void)
{
	subjectTest();
	pressEnter();
	clearScreen();
	myTest();
	pressEnter();
	clearScreen();
	secondTest();
	pressEnter();
	clearScreen();
	fill();
	pressEnter();
	clearScreen();
	return (0);
}