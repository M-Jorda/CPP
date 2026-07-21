#ifndef SPAN_HPP
# define SPAN_HPP

# include <cstdlib>
# include <ctime>
# include <vector>
# include <exception>
# include <numeric>
# include <algorithm>
# include <iterator>
# include <iostream>

class	Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void	addNumber(int num);
		int		shortestSpan();
		int		longestSpan();

		template <typename Iterator>
		void	addNumbers(Iterator begin, Iterator end);

		class	SpanOverflow : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	SpanFull : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		
		class	TooFewNum : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};


	private:
		unsigned int		_N;
		std::vector<int>	span;
};

# include "Span.tpp"

#endif
