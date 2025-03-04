
#ifndef	PMERGEME_HPP
#define	PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{
	public:
		PmergeMe(const std::string &input);
		PmergeMe(const PmergeMe &rhs);
		PmergeMe &operator=(const PmergeMe &rhs);
		~PmergeMe(void);

		void	fillContainers(const std::string &input);

		void	pmergeme();

		bool	checkInput();

		template <typename T>
		T	mergeSort(T container);

		template <typename T>
		T	merge(T a, T b);

	
	private:
		PmergeMe(void);
		std::vector<int>	vecA;
		std::deque<int>		deqA;
		
};

#endif 