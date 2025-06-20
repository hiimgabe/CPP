
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
		throw InvalidInput();
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
	struct	timeval	start, end;
	std::vector<int>	vecBefore = _vec;
	std::deque<int>	deqBefore = _deq;

	gettimeofday(&start, NULL);
	mergeInsertionVec(_vec);
	gettimeofday(&end, NULL);
	double	vecDuration = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);

	gettimeofday(&start, NULL);
	mergeInsertionDeq(_deq);
	gettimeofday(&end, NULL);
	double	deqDuration = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
	
	std::cout << "std::vector before:";
	for (std::vector<int>::iterator it = vecBefore.begin(); it != vecBefore.end(); ++it)
		std::cout << " " << *it;
	std::cout << '\n';
	std::cout << "std::vector after :";
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << " " << *it;
	std::cout << "\n\n";
	std::cout << "std::deque before:";
	for (std::deque<int>::iterator it = deqBefore.begin(); it != deqBefore.end(); ++it)
		std::cout << " " << *it;
	std::cout << '\n';
	std::cout << "std::deque after :";
	for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); ++it)
		std::cout << " " << *it;
	std::cout << "\n\n";
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << vecDuration / 1000000.0 <<" us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << deqDuration / 1000000.0 <<" us" << std::endl;
}

static void	sortPair(std::pair<int, int> &pair)
{
	if (pair.first > pair.second)
		std::swap(pair.first, pair.second);
}

static std::vector<size_t>	jacobGenerate(size_t size)
{
	std::vector<size_t>	res;

	res.push_back(0);
	if (size == 0)
		return (res);
	res.push_back(1);
	if (size == 1)
		return (res);
	for(size_t i = 0; res.back() < size ; i++)
		res.push_back(res[res.size() - 1] + 2 * res[res.size() - 2]);
	return (res);
}

void	PmergeMe::mergeInsertionVec(std::vector<int> &container)
{
	if (container.size() <= 1)
		return ;
	// pair
	std::vector<std::pair<int, int> >	pairs;
	std::vector<int>	leftOver;

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
			leftOver.push_back(container[i]);
		}
	}
	// split pairs
	std::vector<int>	low;
	std::vector<int>	high;
	std::vector<std::pair<int, int> >::iterator	it;
	for (it = pairs.begin() ;it != pairs.end(); ++it)
	{
		low.push_back(it->first);
		high.push_back(it->second);
	}
	// recursion
	mergeInsertionVec(high);
	// insert
	jacobInsertionVec(low, high, leftOver);
	container.clear();
	container = low;
}

// low	:	lower values, or the values that will be inserted into high
//			also our main container
//
// high	:	higher values
//
// leftOver	:	the last value in case of a container having and odd number of elements
void	PmergeMe::jacobInsertionVec(std::vector<int> &low, const std::vector<int> &high, std::vector<int> leftOver)
{
	// check leftover
	std::vector<size_t>	jacob;
	std::vector<int>	merge;
	merge = high;
	if (!leftOver.empty())
	{
		low.push_back(leftOver.back());
		leftOver.pop_back();
	}
	// generate jacobsthal sequence - n = n-1 + (2 * (n - 2))
	jacob = jacobGenerate(low.size());
	// insert according to the sequence
	for (size_t i = 1; i < jacob.size(); i++)
	{
		for (size_t j = jacob[i]; j > jacob[i - 1]; j--)
		{
			if (j <= low.size())
			{
				std::vector<int>::iterator	pos = std::lower_bound(merge.begin(), merge.end(), low[j - 1]);
				merge.insert(pos, low[j - 1]);
			}
		}
	}
	low = merge;
}

void	PmergeMe::mergeInsertionDeq(std::deque<int> &container)
{
	if (container.size() <= 1)
		return ;
	// pair
	std::deque<std::pair<int, int> >	pairs;
	std::deque<int>	leftOver;

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
			leftOver.push_back(container[i]);
		}
	}
	// split pairs
	std::deque<int>	low;
	std::deque<int>	high;
	std::deque<std::pair<int, int> >::iterator	it = pairs.begin();
	for (;it != pairs.end(); ++it)
	{
		low.push_back(it->first);
		high.push_back(it->second);
	}
	// recursion
	mergeInsertionDeq(high);
	// insert
	jacobInsertionDeq(low, high, leftOver);
	container.clear();
	container = low;
}

void	PmergeMe::jacobInsertionDeq(std::deque<int> &low, const std::deque<int> &high, std::deque<int> leftOver)
{
	// check leftover
	std::vector<size_t>	jacob;
	std::deque<int>	merge;
	merge = high;
	if (!leftOver.empty())
	{
		low.push_back(leftOver.back());
		leftOver.pop_back();
	}
	// generate jacobsthal sequence - n = n-1 + (2 * (n - 2))
	jacob = jacobGenerate(low.size());
	// insert according to the sequence
	for (size_t i = 1; i < jacob.size(); i++)
	{
		for (size_t j = jacob[i]; j > jacob[i - 1]; j--)
		{
			if (j <= low.size())
			{
				std::deque<int>::iterator	pos = std::lower_bound(merge.begin(), merge.end(), low[j - 1]);
				merge.insert(pos, low[j - 1]);
			}
		}
	}
	low = merge;
}

const char *PmergeMe::InvalidInput::what(void) const throw() { return("Invalid input."); }