
#ifndef	RPN_HPP
#define	RPN_HPP

#include <iostream>
#include <stdlib.h>
#include <list>
#include <stack>
#include <cstdlib>
#include <sstream>

#define LOG_ERR(str) std::cerr << str << std::endl

class RPN
{
	public:
		RPN(void);
		RPN(const std::string &operation);
		RPN(const RPN &rhs);
		RPN &operator=(const RPN &rhs);
		~RPN(void);

		void	startRPN(void);
		bool	parseString(void);
		void	operate(void);
		bool	checkString(void);
		bool	isDigit(const std::string &str);
		bool	isOperator(int c);
	
	private:
		std::list<std::string>	_list;
		std::string			_str;

};

#endif