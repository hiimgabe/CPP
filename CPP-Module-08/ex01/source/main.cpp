
#include "../include/Span.hpp"

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

	for (int i = 0; i < 100001; i++)
		test.addNumber(i);
	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;
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

int main(void)
{
	subjectTest();
	myTest();
	secondTest();
	return (0);
}