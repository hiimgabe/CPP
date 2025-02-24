
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
	std::string	currStr;
	std::stack<int>	res;
	for (it = _list.begin(); it != _list.end(); ++it)
	{
		currStr = *it;
		//std::cout << "currStr		: " << currStr << "\ncurrStr[0]	: " << currStr[0] << std::endl;
		if (isOperator(currStr[0]) && currStr.size() == 1)
		{
			if (res.size() < 2)
				return (LOG_ERR("Error"), void());
			int	b = res.top();
			res.pop();
			int	a = res.top();
			res.pop();
			switch(currStr[0])
			{
				case '+': res.push(a + b);
					break;
				case '-': res.push(a - b);
					break;
				case '*': res.push(a * b);
					break;
				case '/': res.push(a / b);
					break;
			}
		}
		else
		{
			std::stringstream	ss(currStr);
			int	currInt;
			ss >> currInt;
			res.push(currInt);
		}
	}
	std::cout << res.top() << std::endl;
}

void	RPN::startRPN(void)
{
	if (!parseString())
		return(LOG_ERR("Error"), void());
	operate();
}