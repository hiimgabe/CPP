
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
	int	digitCnt = 0;
	int	operatorCnt = 0;
	std::string	curr;
	std::list<std::string>::iterator	it;
	for(it = _list.begin(); it != _list.end(); ++it)
	{
		if (it->size() > 1 || !isDigit(*it))
			return (false);
		curr = *it;
		for (size_t i = 0; i < curr.size(); i++)
		{
			if (isdigit(curr[i]))
				digitCnt++;
			if (isOperator(curr[i]))
				operatorCnt++;
		}
	}
	if (operatorCnt == (digitCnt - 1))
		return (true);
	return (false);
}

bool	RPN::parseString(void)
{
	std::istringstream	iss(_str);
	std::string	token;
	while (iss >> token)
		this->_list.push_back(token);
	if (!checkString())
		return (false);
	return (true);
}

void	RPN::operate(void)
{
	std::list<std::string>::iterator	it;
	std::cout << "Operating on: " << std::endl;
	//for (it = _list.begin(); it != _list.end(); ++it)
	//{
	//	
	//}
}

void	RPN::startRPN(void)
{
	if (!parseString())
		return(LOG_ERR("Invalid operation."), void());
	operate();
}