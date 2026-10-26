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
		// Build a sorter for the given input.
		// @param values  validated positive integers, kept as strings
		PmergeMe(const std::vector<std::string> &values);
		// Copy constructor: copies the input, both results and both times.
		// @param other  instance to copy
		PmergeMe(const PmergeMe &other);
		// Assignment operator: same copy as the copy constructor.
		// @param other  instance to copy
		// @return       *this
		PmergeMe &operator=(const PmergeMe &other);
		// Destructor: nothing to free, all members manage their own memory.
		~PmergeMe();

		// Convert _values to numbers and sort them with Ford-Johnson
		// on std::vector; the result goes to _vec.
		void	vectorSort();
		// Convert _values to numbers and sort them with Ford-Johnson
		// on std::deque; the result goes to _deq.
		void	dequeSort();
		// Print the four output lines on stdout: Before (input),
		// After (sorted), then the time taken by each container.
		void	printInfo() const;

		// Thrown when no number is given on the command line.
		// Constructors: default message (usage line), or a custom one.
		// @param msg    custom message returned by what()
		// @param other  exception to copy (copy constructor / operator=)
		class	UsageError : public std::runtime_error
		{
			public:
				UsageError();
				UsageError(std::string const &msg);
				UsageError(UsageError const &other);
				UsageError &operator=(UsageError const & other);
				~UsageError() throw();
		};

		// Thrown when an argument is not a valid positive integer.
		// Constructors: default message, or a custom one naming the input.
		// @param msg    custom message returned by what()
		// @param other  exception to copy (copy constructor / operator=)
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

		// Private and unused: a sorter always needs its input values.
		PmergeMe();

		// Compare two elements by value and count one comparison.
		// @param a  left element
		// @param b  right element
		// @return   true if a.value < b.value
		bool					lessThan(const Element &a, const Element &b);
		// Ford-Johnson sort (merge-insertion): pair the elements, sort the
		// larges recursively, then insert the smalls into them.
		// @param elems  elements to sort, sorted in place
		void					mergeInsert(std::vector<Element> &elems);
		// Split elems into pairs and order each pair (one comparison).
		// @param elems    elements to pair; even size (straggler removed)
		// @param larges   out: the larger element of each pair
		// @param partner  out: the smaller element, stored at partner[large.id]
		void					makePairs(std::vector<Element> &elems,
					std::vector<Element> &larges, std::vector<Element> &partner);
		// Build the main chain: b1 then all larges, then insert the other
		// smalls and the straggler in Jacobsthal order, each one searched
		// only up to the current position of its large.
		// @param larges        the larges, already sorted
		// @param partner       the smalls, indexed by the id of their large
		// @param hasStraggler  true if the input had an odd element left over
		// @param odd           the straggler; ignored if hasStraggler is false
		// @return              the fully sorted chain
		std::vector<Element>	buildChain(std::vector<Element> &larges,
					std::vector<Element> &partner, bool hasStraggler,
					const Element &odd);
		// Insertion order of the smalls, by groups bounded by Jacobsthal
		// numbers, each group in decreasing order; index 0 (b1) excluded.
		// Shared by the vector and deque versions.
		// @param n  number of smalls to insert, straggler included
		// @return   0-based indices, e.g. n = 5 gives [2, 1, 4, 3]
		static std::vector<size_t>	jacobsthalOrder(size_t n);
		// Insert elem into the sorted chain by binary search.
		// @param chain  sorted elements, elem is inserted in place
		// @param elem   element to insert
		// @param high   search bound (exclusive): only chain[0, high) is searched
		void					binaryInsert(std::vector<Element> &chain,
					const Element &elem, size_t high);

		// Overload of mergeInsert for std::deque: same parameters and behaviour.
		void				mergeInsert(std::deque<Element> &elems);
		// Overload of makePairs for std::deque: same parameters and behaviour.
		void				makePairs(std::deque<Element> &elems,
					std::deque<Element> &larges, std::deque<Element> &partner);
		// Overload of buildChain for std::deque: same parameters and behaviour,
		// returns the sorted chain as a std::deque.
		std::deque<Element>	buildChain(std::deque<Element> &larges,
					std::deque<Element> &partner, bool hasStraggler,
					const Element &odd);
		// Overload of binaryInsert for std::deque: same parameters and behaviour.
		void				binaryInsert(std::deque<Element> &chain,
					const Element &elem, size_t high);
};

#endif
