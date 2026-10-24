#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <iostream>
# include <sstream>
# include <stdexcept>

class	PmergeMe
{
	public:
		PmergeMe(const std::vector<std::string> &values);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	vectorSort();
		void	dequeSort();
		void	printInfo() const;

		class	UsageError : public std::runtime_error
		{
			public:
				UsageError();
				UsageError(std::string const &msg);
				UsageError(UsageError const &other);
				UsageError &operator=(UsageError const & other);
				~UsageError() throw();
		};

		class	InputError : public std::runtime_error
		{
			public:
				InputError();
				InputError(std::string const &msg);
				InputError(InputError const &other);
				InputError &operator=(InputError const &other);
				~InputError() throw();
		};

	private:
		std::vector<std::string>	_values;
		std::vector<long>			_vec;
		std::deque<long>			_deq;
		double						_timeVec;
		double						_timeDeq;
		size_t						_comparison;
		
		struct	Element
		{
			long	value;
			size_t	id;
		};
	
		PmergeMe();

		bool					lessThan(const Element &a, const Element &b);
		void					mergeInsert(std::vector<Element> &elems);
		void					makePairs(std::vector<Element> &elems,
					std::vector<Element> &larges, std::vector<Element> &partner);
		std::vector<Element>	buildChain(std::vector<Element> &larges,
					std::vector<Element> &partner);
		void					binaryInsert(std::vector<Element> &chain,
					const Element &elem, size_t high);
};

#endif
