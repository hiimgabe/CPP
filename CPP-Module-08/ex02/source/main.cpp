
#include "../include/MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>

void	subjectTest()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Size before pop(): " << mstack.size() << '\n';
	std::cout << "Top before pop(): " << mstack.top() << "\n\n";
	mstack.pop();
	std::cout << "Size after pop(): " << mstack.size() << '\n';
	std::cout << "Top before pop(): " << mstack.top() << "\n\n";
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();
	MutantStack<int>::const_iterator cit = mstack.begin();
	MutantStack<int>::const_iterator cite = mstack.end();
	std::cout << "==== iterator ====\n++i\n\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "\n==== iterator ====\n--i\n\n";
	while (it != mstack.begin())
	{
		--it;
		std::cout << *it << std::endl;
	}
	std::cout << "\n==== const_iterator ====\n++i\n\n";
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}
	std::cout << "\n==== const_iterator ====\n--i\n\n";
	while (cit != mstack.begin())
	{
		--cit;
		std::cout << *cit << std::endl;
	}
	std::stack<int>	s(mstack);
}

void	subjectListTest()
{
	std::list<int>	mstack;

	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << "Size before pop(): " << mstack.size() << '\n';
	std::cout << "Top before pop(): " << mstack.back() << "\n\n";
	mstack.pop_back();
	std::cout << "Size after pop(): " << mstack.size() << '\n';
	std::cout << "Top before pop(): " << mstack.back() << "\n\n";
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator	it = mstack.begin();
	std::list<int>::iterator	ite = mstack.end();
	std::list<int>::const_iterator	cit = mstack.begin();
	std::list<int>::const_iterator	cite = mstack.end();
	std::cout << "==== iterator ====\n++i\n\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "\n==== iterator ====\n--i\n\n";
	while (it != mstack.begin())
	{
		--it;
		std::cout << *it << std::endl;
	}
	std::cout << "\n==== const_iterator ====\n++i\n\n";
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}
	std::cout << "\n==== const_iterator ====\n--i\n\n";
	while (cit != mstack.begin())
	{
		--cit;
		std::cout << *cit << std::endl;
	}
}

void	subjectVectorTest()
{
	std::vector<int>	mstack;

	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << "Size before pop(): " << mstack.size() << '\n';
	std::cout << "Top before pop(): " << mstack.back() << "\n\n";
	mstack.pop_back();
	std::cout << "Size after pop(): " << mstack.size() << '\n';
	std::cout << "Top before pop(): " << mstack.back() << "\n\n";
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::vector<int>::iterator	it = mstack.begin();
	std::vector<int>::iterator	ite = mstack.end();
	std::vector<int>::const_iterator	cit = mstack.begin();
	std::vector<int>::const_iterator	cite = mstack.end();
	std::cout << "==== iterator ====\n++i\n\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "\n==== iterator ====\n--i\n\n";
	while (it != mstack.begin())
	{
		--it;
		std::cout << *it << std::endl;
	}
	std::cout << "\n==== const_iterator ====\n++i\n\n";
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}
	std::cout << "\n==== const_iterator ====\n--i\n\n";
	while (cit != mstack.begin())
	{
		--cit;
		std::cout << *cit << std::endl;
	}
}

void	reverseIteratorMutantStack()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Size before pop(): " << mstack.size() << '\n';
	std::cout << "Top before pop(): " << mstack.top() << "\n\n";
	mstack.pop();
	std::cout << "Size after pop(): " << mstack.size() << '\n';
	std::cout << "Top before pop(): " << mstack.top() << "\n\n";
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::reverse_iterator	it = mstack.rbegin();
	MutantStack<int>::reverse_iterator	ite = mstack.rend();
	MutantStack<int>::const_reverse_iterator cit = mstack.rbegin();
	MutantStack<int>::const_reverse_iterator cite = mstack.rend();
	std::cout << "==== reverse_iterator ====\n++i\n\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "\n==== reverse_iterator ====\n--i\n\n";
	while (it != mstack.rbegin())
	{
		--it;
		std::cout << *it << std::endl;
	}
	std::cout << "\n==== const_reverse_iterator ====\n++i\n\n";
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}
	std::cout << "\n==== const_reverse_iterator ====\n--i\n\n";
	while (cit != mstack.rbegin())
	{
		--cit;
		std::cout << *cit << std::endl;
	}
	std::stack<int>	s(mstack);
}

void	reverseIteratorList()
{
	std::list<int>	mstack;

	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << "Size before pop(): " << mstack.size() << '\n';
	std::cout << "Top before pop(): " << mstack.back() << "\n\n";
	mstack.pop_back();
	std::cout << "Size after pop(): " << mstack.size() << '\n';
	std::cout << "Top before pop(): " << mstack.back() << "\n\n";
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::reverse_iterator	it = mstack.rbegin();
	std::list<int>::reverse_iterator	ite = mstack.rend();
	std::list<int>::const_reverse_iterator	cit = mstack.rbegin();
	std::list<int>::const_reverse_iterator	cite = mstack.rend();
	std::cout << "==== reverse_iterator ====\n++i\n\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "\n==== reverse_iterator ====\n--i\n\n";
	while (it != mstack.rbegin())
	{
		--it;
		std::cout << *it << std::endl;
	}
	std::cout << "\n==== const_reverse_iterator ====\n++i\n\n";
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}
	std::cout << "\n==== const_reverse_iterator ====\n--i\n\n";
	while (cit != mstack.rbegin())
	{
		--cit;
		std::cout << *cit << std::endl;
	}
}

void	reverseIteratorVector()
{
	std::vector<int>	mstack;

	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << "Size before pop(): " << mstack.size() << '\n';
	std::cout << "Top before pop(): " << mstack.back() << "\n\n";
	mstack.pop_back();
	std::cout << "Size after pop(): " << mstack.size() << '\n';
	std::cout << "Top before pop(): " << mstack.back() << "\n\n";
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::vector<int>::reverse_iterator	it = mstack.rbegin();
	std::vector<int>::reverse_iterator	ite = mstack.rend();
	std::vector<int>::const_reverse_iterator	cit = mstack.rbegin();
	std::vector<int>::const_reverse_iterator	cite = mstack.rend();
	std::cout << "==== reverse_iterator ====\n++i\n\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "\n==== reverse_iterator ====\n--i\n\n";
	while (it != mstack.rbegin())
	{
		--it;
		std::cout << *it << std::endl;
	}
	std::cout << "\n==== const_reverse_iterator ====\n++i\n\n";
	while (cit != cite)
	{
		std::cout << *cit << std::endl;
		++cit;
	}
	std::cout << "\n==== const_reverse_iterator ====\n--i\n\n";
	while (cit != mstack.rbegin())
	{
		--cit;
		std::cout << *cit << std::endl;
	}
}

int	main()
{
	std::cout << "==== ITERATORS && CONST_ITERATORS ====\n\n";
	std::cout << "==== MutantStack ====\n\n";
	subjectTest();
	std::cout << "\n==== std::list ====\n\n";
	subjectListTest();
	std::cout << "\n==== std::vector ====\n\n";
	subjectVectorTest();
	std::cout << "\n==== REVERSE_ITERATORS && CONST_REVERSE_ITERATORS ====\n\n";
	std::cout << "==== MutantStack ====\n\n";
	reverseIteratorMutantStack();
	std::cout << "\n==== std::list ====\n\n";
	reverseIteratorList();
	std::cout << "\n==== std::vector ====\n\n";
	reverseIteratorVector();

	return (0);
}