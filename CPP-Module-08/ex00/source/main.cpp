#include "../include/EasyFind.hpp"
#include <vector>
#include <list>
#include <deque>

void	intVectorTest()
{
	std::vector<int>	intVector;
	
	std::cout << "\nworking with int vector:\n\n";
	for (int i = 0; i < 6; i++)
	{
		intVector.push_back(i * 2);
		std::cout << "intVector[" << i << "] = " << intVector[i] << std::endl;
	}

	std::cout << "\n==== Testing ===\n" << std::endl;
	try
	{
		std::cout << "Checking for: 10\t" << find(intVector, 10) << std::endl;
		std::cout << "Checking for: 3\t\t" << find(intVector, 3) << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	intDequeTest()
{
	std::deque<int>	intDeque;
	
	std::cout << "\n\nworking with int deque:\n\n";
	for (int i = 0; i < 6; i++)
	{
		intDeque.push_back(i * 2);
		std::cout << "intDeque[" << i << "] = " << intDeque[i] << std::endl;
	}

	std::cout << "\n==== Testing ===\n" << std::endl;
	try
	{
		std::cout << "Checking for: 10\t" << find(intDeque, 10) << std::endl;
		std::cout << "Checking for: 3\t\t" << find(intDeque, 3) << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	intListTest()
{
	std::list<int>	intList;
	
	std::cout << "\n\nworking with int list:\n\n";
	for (int i = 0; i < 6; i++)
	{
		intList.push_back(i * 2);
		std::cout << "intList i: " << i << " = " << i * 2 << std::endl;
	}

	std::cout << "\n==== Testing ===\n" << std::endl;
	try
	{
		std::cout << "Checking for: 10\t" << find(intList, 10) << std::endl;
		std::cout << "Checking for: 3\t\t" << find(intList, 3) << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	intVectorTest();
	intListTest();
	intDequeTest();
	
	return (0);
}