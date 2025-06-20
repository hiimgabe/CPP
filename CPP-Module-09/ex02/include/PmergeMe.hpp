
#ifndef	PMERGEME_HPP
#define	PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <deque>
#include <iomanip>

#define INT_MAX 2147483647

class PmergeMe
{
	public:
		PmergeMe(const std::string &input);
		PmergeMe(const PmergeMe &rhs);
		PmergeMe &operator=(const PmergeMe &rhs);
		~PmergeMe(void);

		void	pmergeme();

		bool	checkInput();
		bool	checkInputChar();
		bool	checkInputTokens();
		bool	isNumber(const std::string &str);

		void	mergeInsertionVec(std::vector<int> &container);
		void	jacobInsertionVec(std::vector<int> &low, const std::vector<int> &high, std::vector<int> leftOver);

		void	mergeInsertionDeq(std::deque<int> &container);
		void	jacobInsertionDeq(std::deque<int> &low, const std::deque<int> &high, std::deque<int> leftOver);

		class InvalidInput : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
	
	private:
		PmergeMe(void);
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		std::string			_input;
		
};

#endif 