
#ifndef	PMERGEME_HPP
#define	PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <sys/time.h>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <deque>

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

		template <typename T>
		void	mergeInsertion(T &container);

		template <typename T>
		void	PmergeMe::jacobInsertion(T low, T high, T leftOver);

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