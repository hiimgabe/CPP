
#include "../include/Span.hpp"

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
	if (_v.size() < _size)
		_v.push_back(n);
	else
	{
		std::cout << "HELOO" << std::endl;
		throw SpanFull();
	}

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