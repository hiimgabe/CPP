
#include "../include/MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>

void	subjectTest()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	++it;
	--ite;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int>	s(mstack);
}

void	subjectListTest()
{
	std::list<int>	mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;

	mstack.pop_front();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);

	std::list<int>::iterator	it = mstack.begin();
	std::list<int>::iterator	ite = mstack.end();

	++it;
	--ite;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	subjectVectorTest()
{
	std::vector<int>	mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);

	std::vector<int>::iterator	it = mstack.begin();
	std::vector<int>::iterator	ite = mstack.end();

	++it;
	--ite;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	reverseIteratorMutantStack()
{
	MutantStack<int>	mstack;

	mstack.push(2);
	mstack.push(22);
	mstack.push(52);
	mstack.push(43);

	MutantStack<int>::reverse_iterator it = mstack.rbegin();
	MutantStack<int>::reverse_iterator ite = mstack.rend();


	std::cout << "\n==== MutantStack reverse_iterator ====\n\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int	main()
{
	//std::cout << "\n==== Subject Test with MutantStack, std::list and std::vector ====\n\n"; 
	//std::cout << "==== MutantStack ====\n\n";
	//subjectTest();
	//std::cout << "\n==== std::list ====\n\n";
	//subjectListTest();
	//std::cout << "\n==== std::vector ====\n\n";
	//subjectVectorTest();

	// reverse iterator
	reverseIteratorMutantStack();

	// const iterator

	// reverse const iterator

	return (0);
}