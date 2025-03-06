
#include "../include/PmergeMe.hpp"


template <typename T>
T firstHalf(T container)
{
	typename T::iterator	it;
	T	res;

	it = container.begin();
	for (size_t i = 0; i < container.size() / 2; i++)
	{
		res.push_back(*it);
		++it;
	}
	return (res);
}

template <typename T>
T secondHalf(T container)
{
	typename T::iterator	it;
	T	res;

	it = container.begin();
	for (size_t i = 0; i < container.size() / 2; i++)
		++it;
	for (;it != container.end(); ++it)
		res.push_back(*it);
	return (res);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		PmergeMe	merge(argv[1]);
		
		std::vector<int>	testVec;
		std::deque<int>	testDeq;

		for (int i = 0; i < 6; i++)
		{
			testVec.push_back(i);
			testDeq.push_back(i);
			std::cout << testVec.back() << std::endl;
			std::cout << testDeq.back() << std::endl;
		}

		
		std::vector<int>	firstHalfVec = firstHalf(testVec);
		std::vector<int>	secondHalfVec = secondHalf(testVec);
		std::deque<int>	firstHalfDeq = firstHalf(testDeq);
		std::deque<int>	secondHalfDeq = secondHalf(testDeq);

		std::cout << "First half" << std::endl;
		std::vector<int>::iterator	itFHVEC;
		std::deque<int>::iterator	itFHDEQ;
		for (itFHVEC = firstHalfVec.begin(); itFHVEC != firstHalfVec.end(); ++itFHVEC)
			std::cout << *itFHVEC << std::endl;
		std::cout << std::endl;
		for (itFHDEQ = firstHalfDeq.begin(); itFHDEQ != firstHalfDeq.end(); ++itFHDEQ)
			std::cout << *itFHDEQ << std::endl;
		std::cout << std::endl;
		std::cout << "Second half" << std::endl;
		for (itFHVEC = secondHalfVec.begin(); itFHVEC != secondHalfVec.end(); ++itFHVEC)
			std::cout << *itFHVEC << std::endl;
		std::cout << std::endl;
		for (itFHDEQ = secondHalfDeq.begin(); itFHDEQ != secondHalfDeq.end(); ++itFHDEQ)
			std::cout << *itFHDEQ << std::endl;
		std::cout << std::endl;



		//merge.pmergeme();
	}
	else
		std::cerr << "Invalid number of arguments." << std::endl;

	return (0);
}