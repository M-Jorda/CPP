#include "PmergeMe.hpp"

#include <sstream>
#include <algorithm>
#include <cstdlib>

#define ERRUSAGE	"usage: ./PmergeMe <positive integers>"
#define INPUSAGE	"input error"
#define STR_BEF		"Before: "
#define STR_AFT		"After: "
#define STR_PROCESS	"Time to process a range of "
#define STR_ELEM	" elements with "

using	std::cout;
using	std::endl;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const std::vector<std::string> &values)
	: _values(values), _timeVec(0), _timeDeq(0), _comparison(0) {}

PmergeMe::PmergeMe(const PmergeMe &other)
	: _values(other._values), _vec(other._vec)
	, _deq(other._deq), _timeVec(other._timeVec)
	, _timeDeq(other._timeDeq), _comparison(other._comparison) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_values = other._values;
		_vec = other._vec;
		_deq = other._deq;
		_timeVec = other._timeVec;
		_timeDeq = other._timeDeq;
		_comparison = other._comparison;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::vectorSort()
{
	std::vector<Element>	vec;

	for (size_t i = 0; i < _values.size(); i++)
	{
		Element				elem;

		elem.value = std::strtol(_values[i].c_str(), NULL, 10);
		elem.id = i;
		vec.push_back(elem);
	}
	mergeInsert(vec);
	for (size_t i = 0; i < _values.size(); i++)
		_vec.push_back(vec[i].value);
}

void	PmergeMe::dequeSort()
{

}

PmergeMe::UsageError::UsageError()
	: std::runtime_error(ERRUSAGE) {}

PmergeMe::UsageError::UsageError(std::string const &msg)
	: std::runtime_error(msg) {}

PmergeMe::UsageError::UsageError(UsageError const &other)
	: std::runtime_error(other) {}

PmergeMe::UsageError &PmergeMe::UsageError::operator=(UsageError const & other)
{
	std::runtime_error::operator=(other);
	return (*this);
}

PmergeMe::UsageError::~UsageError() throw() {}

PmergeMe::InputError::InputError()
	: std::runtime_error(INPUSAGE) {}

PmergeMe::InputError::InputError(std::string const &msg)	
	: std::runtime_error(msg) {}

PmergeMe::InputError::InputError(InputError const &other)
	: std::runtime_error(other) {}

PmergeMe::InputError &PmergeMe::InputError::operator=(InputError const &other)
{
	std::runtime_error::operator=(other);
	return (*this);
}

PmergeMe::InputError::~InputError() throw() {}

template <typename C>
static std::string	toString(const C &c)
{
	std::ostringstream	out;
	for (typename C::const_iterator it = c.begin(); it != c.end(); ++it)
	{
		if (it != c.begin())
			out << " ";
		out << *it;
	}
	return (out.str());
}

void	PmergeMe::printInfo() const
{
	cout << STR_BEF << toString(_values) << endl;
	cout << STR_AFT << toString(_vec) << endl;
	cout << STR_PROCESS << _vec.size() << STR_ELEM << "std::vector : " << _timeVec << endl;
	cout << STR_PROCESS << _deq.size() << STR_ELEM << "std::deque : " << _timeDeq << endl;
}

bool	PmergeMe::lessThan(const Element &a, const Element &b)
{
	_comparison++;
	return (a.value < b.value);
}

void	PmergeMe::binaryInsert(std::vector<Element> &chain, const Element &elem,
		size_t high)
{
	size_t	low = 0;

	while (low < high)
	{
		size_t	mid = (low + high) / 2;
		if (lessThan(elem, chain[mid]))
			high = mid;
		else
			low = mid + 1;
	}
	chain.insert(chain.begin() + low, elem);
}

void	PmergeMe::makePairs(std::vector<Element> &elems, std::vector<Element> &larges,
		std::vector<Element> &partner)
{
	for (size_t i = 0; i < elems.size(); i += 2)
	{
		Element					large;
		Element					small;

		large = elems[i];
		small = elems[i + 1];
		if (lessThan(elems[i], elems[i + 1]))
			std::swap(large, small);
		larges.push_back(large);
		partner[large.id] = small;
	}
}

std::vector<PmergeMe::Element>	PmergeMe::buildChain(std::vector<Element> &larges,
		std::vector<Element> &partner)
{
	std::vector<Element>	chain;

	chain.push_back(partner[larges[0].id]);
	chain.push_back(larges[0]);
	for (size_t i = 1; i < larges.size(); i++)
	{
		chain.push_back(larges[i]);
		binaryInsert(chain, partner[larges[i].id], chain.size());
	}
	return (chain);
}


void	PmergeMe::mergeInsert(std::vector<Element> &elems)
{
	std::vector<Element>	partner(_values.size());
	std::vector<Element>	larges;
	Element					odd;
	bool					hasStraggler;
	std::vector<Element>	chain;

	larges.reserve(elems.size() / 2);
	if (elems.size() <= 1)
		return ;
	if ((elems.size() % 2) == 1)
	{
		odd = elems.back();
		elems.pop_back();
		hasStraggler = true;
	}
	else
		hasStraggler = false;
	makePairs(elems, larges, partner);
	mergeInsert(larges);
	chain = buildChain(larges, partner);
	if (hasStraggler)
		binaryInsert(chain, odd, chain.size());
	elems = chain;
}
