
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
		throw InvalidInput();
	}
	else
		std::cout << "Valid input." << std::endl;
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
	if (_vec.size() > 3000 || _deq.size() > 3000)
		return (false);
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
	std::vector<int>	vecRes;
	std::deque<int>		deqRes;
	struct	timeval	start, end;

	gettimeofday(&start, NULL);
	vecRes = mergeInsertion(_vec);
	gettimeofday(&end, NULL);
	double	vecDuration = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);

	gettimeofday(&start, NULL);
	deqRes = mergeInsertion(_deq);
	gettimeofday(&end, NULL);
	double	deqDuration = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
	
	std::cout << "Before:";
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
	std::cout << "After :";
	for (std::deque<int>::iterator it = deqRes.begin(); it != deqRes.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << vecDuration <<" us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << deqDuration <<" us" << std::endl;
}

template <typename T>
static void	sortPair(std::pair<int, int> &pair)
{
	if (pair->first > pair->second)
		std::swap(pair->first, pair->second);
}

template <typename T>
void	PmergeMe::mergeInsertion(T &container)
{
	if (container.size() <= 1)
		return ;
	// pair
	std::T<std::pair<int, int>>	pairs;
	std::T<int>	leftOver;

	for (size_t i = 0; i < container.size(); i += 2)
	{
		if (i + 1 < container.size())
		{
			std::pair<int, int>	tmpPair = std::make_pair(container[i], container[i + 1]);
			sortPair(tmpPair);
			pairs.push_back(tmpPair);
		}
		else
		{
			leftOver.clear();
			leftOver.push_back(vec[i]);
		}
	}
	// split pairs
	std::T<int>	low;
	std::T<int>	high;
	std::T<std::pair<int, int> >::iterator	it = pair.begin();
	for (;it != pair.end(); ++it)
	{
		low.push_pack(it->first);
		high.push_pack(it->second);
	}
	// recursion
	mergeInsertion(high);
	// insert
	jacobInsertion(low, high, leftOver);
}

template <typename T>
void	PmergeMe::jacobInsertion(T low, T high, T leftOver)
{
	// check leftover
	// generate jacobsthal sequence - n = n-1 + (2 * (n - 2))
	// insert according to the sequence
}

const char *PmergeMe::InvalidInput::what(void) const throw() { return("Invalid input."); }