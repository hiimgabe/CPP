
#include "../include/RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const std::string &operation)
{
	this->_str = operation;
}

RPN::RPN(const RPN &rhs)
{
	*this = rhs;
}

RPN &RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		this->_list = rhs._list;
		this->_str = rhs._str;
	}
	return (*this);
}

RPN::~RPN(void)
{}

bool	RPN::isOperator(int c)
{
	return (c == 42 || c == 43 || c == 45 || c == 47);
}

bool	RPN::isDigit(const std::string &str)
{
	for(size_t i = 0; i < str.size(); i++)
		if (!isdigit(str[i]) && !isOperator(str[i]))
			return (false);
	return (true);
}

bool	RPN::checkString(void)
{
	std::list<std::string>::iterator	it;
	for(it = _list.begin(); it != _list.end(); ++it)
	{
		if (it->size() > 1 || !isDigit(*it))
			return (false);
	}
	//check if string has x numbers && x-1 operators
	return (true);
}

void	RPN::parseString(void)
{
	std::istringstream	iss(_str);
	std::string	token;
	while (iss >> token)
		this->_list.push_back(token);
	if (!checkString())
		{return (LOG_ERR("Invalid operation."), void());}
		std::list<std::string>::iterator	it;
	for (it = _list.begin(); it != _list.end(); ++it)
		std::cout << *it << std::endl;
}

void	RPN::operate(void)
{}

void	RPN::startRPN(void)
{
	parseString();
	operate();
}