#include "PmergeMe.hpp"

#include <sstream>

using	std::cout;
using	std::endl;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const std::vector<std::string> &values) : _values(values), _timeVec(0), _timeDeq(0) {}

PmergeMe::PmergeMe(const PmergeMe &other) : _values(other._values), _vec(other._vec), _deq(other._deq), _timeVec(other._timeVec), _timeDeq(other._timeDeq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_values = other._values;
		_vec = other._vec;
		_deq = other._deq;
		_timeVec = other._timeVec;
		_timeDeq = other._timeDeq;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::vectorSort()
{

}

void	PmergeMe::dequeSort()
{

}

PmergeMe::UsageError::UsageError() : std::runtime_error("usage: ./PmergeMe <positive integers>") {}

PmergeMe::UsageError::UsageError(std::string const &msg) : std::runtime_error(msg) {}

PmergeMe::UsageError::UsageError(UsageError const &other) : std::runtime_error(other) {}

PmergeMe::UsageError &PmergeMe::UsageError::operator=(UsageError const & other)
{
	std::runtime_error::operator=(other);
	return (*this);
}

PmergeMe::UsageError::~UsageError() throw() {}

PmergeMe::InputError::InputError() : std::runtime_error("input error") {}

PmergeMe::InputError::InputError(std::string const &msg) : std::runtime_error(msg) {}

PmergeMe::InputError::InputError(InputError const &other) : std::runtime_error(other) {}

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
	cout << "Before:\t" << toString(_values) << endl;
	cout << "After: " << toString(_vec) << endl;
	cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << _timeVec << endl;
	cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << _timeDeq << endl;
}
