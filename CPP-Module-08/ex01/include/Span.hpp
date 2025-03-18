
#ifndef	SPAN_HPP
#define	SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

#ifdef DEBUG
#define LOG(str) std::cout << str << std::endl;
#else
#define LOG(str)
#endif

class Span
{
	public:
		Span(void);
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span(void);

		void	addNumber(int n);
		void	fill();
		int	shortestSpan(void);
		int	longestSpan(void);

		int	max() const;
		int	min() const;

		class NoSpan : public std::exception
		{
			public:
				const char *what() const throw() { return ("Invalid span."); }
		};

		class SpanFull : public std::exception
		{
			public:
				const char *what() const throw() { return ("Can't add more numbers, Span is full."); }
		};


	private:
		std::vector<int>	_v;
		unsigned int		_size;
};

#endif