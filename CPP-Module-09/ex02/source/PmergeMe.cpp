
#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
	*this = rhs;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		this->_vec = rhs._vec;
		this->_deq = rhs._deq;
	}
	return (*this);
}

PmergeMe::PmergeMe(const std::string &input): _input(input)
{
	if (!checkInput())
	{
		std::cerr << "Invalid input." << std::endl;
	}
	else
		std::cout << "Valid input." << std::endl;
	//fillContainers(input);
}

PmergeMe::~PmergeMe(void)
{
	// destructor
}

bool	PmergeMe::isNumber(const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
		if (!isdigit(str[i]))
			return (false);
	return (true);
}

bool	PmergeMe::checkInputChar()
{
	for (size_t i = 0; i < _input.size(); i++)
	{
		if (!std::isspace(_input[i]) && !std::isdigit(_input[i]))
			return (false);
		else if (_input[i] == '-')
			return (false);
	}
	return (true);
}

bool	PmergeMe::checkInputTokens()
{
	std::vector<std::string>	res;
	std::vector<long int>		intV;
	std::istringstream	iss(_input);
	std::string	token;
	
	while(std::getline(iss, token, ' '))
	{
		res.push_back(token);
	}
	std::vector<std::string>::iterator	it;
	for (it = res.begin(); it != res.end(); ++it)
	{
		std::string curr = *it;
		if (curr.empty())
			continue ;
		else
		{
			long int	currL = std::atol(curr.c_str());
			if (std::find(intV.begin(), intV.end(), currL) != intV.end())
				return (false);
			intV.push_back(std::atol(curr.c_str()));
		}
	}
	std::vector<long int>::iterator	itL;
	for(itL = intV.begin(); itL != intV.end(); ++itL)
	{
		long int	curr = *itL;
		if (curr > INT_MAX)
			return (false);
		else
		{
			_vec.push_back(curr);
			_deq.push_back(curr);
		}
	}
	return (true);
}

bool	PmergeMe::checkInput()
{
	if (!checkInputChar())
		return (false);
	if (!checkInputTokens())
		return (false);
	return (true);
}

void	PmergeMe::pmergeme()
{
	std::vector<int>::iterator	itVec;
	std::deque<int>::iterator	itDeq;

	for (itVec = _vec.begin(); itVec != _vec.end(); ++itVec)
		std::cout << *itVec << std::endl;
	std::cout << std::endl;
	for (itDeq = _deq.begin(); itDeq != _deq.end(); ++itDeq)
		std::cout << *itDeq << std::endl;
}

template <typename T>
T PmergeMe::firstHalf(T container)
{
	typedef T::iterator	it;
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
T PmergeMe::secondHalf(T container)
{
	typedef T::iterator	it;
	T	res;

	it = container.begin();
	for (size_t i = 0; i < container.size() / 2; i++)
		++it;
	for (;it != container.end(); ++it)
		res.push(*it);
	return (res);
}

template <typename T>
T	PmergeMe::mergeSort(T container)
{
	if (container.size() == 1)
		return (container);
	
	T	a = firstHalf(container);
	T	b = secondHalf(container);
	a = mergeSort(a);
	b = mergeSort(b);
	return (merge(a, b));
}

template <typename T>
T	PmergeMe::merge(T a, T b)
{
	
}