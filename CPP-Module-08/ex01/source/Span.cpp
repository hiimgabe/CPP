
#include "../include/Span.hpp"

/*
	- std::sort
		usage: sorts the Span
	
	- std::min_element
	- std::max_element
		usage: getting the max or min value of the Span
	
	- std::rand
	- std::srand
	- std::time
		usage: rand() used to help fill Span, srand() and time() used to get random numbers

	- std::generate
		usage: to fill a Span with random numbers
*/

Span::Span(void)
{
	LOG("Span Default Constructor called.");
	_size = 0;
}

Span::Span(unsigned int n)
{
	LOG("Span unsigned int Constructor called.");
	this->_size = n;
}

Span::Span(const Span &other)
{
	LOG("Span Copy Constructor called.");
	*this = other;
}

Span	&Span::operator=(const Span &other)
{
	LOG("Span Assign Operator Overload called.");
	if (this != &other)
	{
		this->_size = other._size;
		this->_v = other._v;
	}
	return (*this);
}

Span::~Span(void)
{
	LOG("Span Destructor called.");
}

void	Span::addNumber(int n)
{
	if (n < 0)
		throw NegativeValue();
	if (_v.size() < _size)
		_v.push_back(n);
	else
		throw SpanFull();
}

int	Span::shortestSpan(void)
{
	if (_v.size() < 2)
		throw NoSpan();
	std::sort(_v.begin(), _v.end());
	int	shortSpan = INT_MAX;
	for (size_t i = 1; i < _v.size(); i++)
	{
		int	tmpSpan = _v[i] - _v[i - 1];
		if (tmpSpan < shortSpan)
			shortSpan = tmpSpan;
	}
	return (shortSpan);
}

int	Span::longestSpan(void)
{
	if (_v.size() < 2)
		throw NoSpan();
	int	min = *std::min_element(_v.begin(), _v.end());
	int	max = *std::max_element(_v.begin(), _v.end());
	return (max - min);
}

static int	getRandom() { return(std::rand() % 100000); }

void	Span::fill()
{
	_v.resize(_size);
	std::srand(std::time(0));
	std::generate(_v.begin(), _v.end(), getRandom);
}

int	Span::max() const { return(*(std::max_element(_v.begin(), _v.end()))); }

int	Span::min() const { return(*(std::min_element(_v.begin(), _v.end()))); }

const char	*Span::NoSpan::what() const throw()
{
	return ("Invalid Span.");
}

const char	*Span::SpanFull::what() const throw()
{
	return ("Can't add more numbers, Span is full.");
}

const char	*Span::NegativeValue::what() const throw()
{
	return ("Negative numbers not allowed.");
}