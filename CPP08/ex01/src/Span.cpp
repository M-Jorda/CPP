#include "Span.hpp"

using std::cout;
using std::endl;

Span::Span() : _N(0)
{
	cout << "Creation of standard Span" << endl;
}

Span::Span(unsigned int N) : _N(N)
{
	cout << "Creation of Span" << endl;
}

Span::Span(const Span& other) : _N(other._N)
{
	cout << "Creation of a copy of Span" << endl;
}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
    {
		cout << "Assignation of a copy of Span"<< endl;
		_N = other._N;
    }
    return (*this);
}

Span::~Span()
{
	cout << "Destruction of Span" << endl;
}

void	Span::addNumber(int num)
{
	if (span.size() == _N)
		throw SpanFull();
	span.push_back(num);
}

int	Span::shortestSpan()
{
	size_t	size = span.size();

	if (size < 2)
		throw TooFewNum();

	std::vector<int>	diffs(size);

	std::sort(span.begin(), span.end());
	std::adjacent_difference(span.begin(), span.end(), diffs.begin());

	return (*std::min_element(diffs.begin() + 1, diffs.end()));
}

int	Span::longestSpan()
{
	if (span.size() < 2)
		throw TooFewNum();

	int	min = *std::min_element(span.begin(), span.end());
	int	max = *std::max_element(span.begin(), span.end());

	return (max - min);
}

template <typename Iterator>
void	Span::addNumbers(Iterator begin, Iterator end)
{
	if (begin == end)
		throw SpanFull();
	while (begin != end)
		span.push_back(*begin++);
}

const char	*Span::SpanFull::what() const throw()
{
	return ("The span is full");
}

const char	*Span::TooFewNum::what() const throw()
{
	return ("The span need at least two numbers");
}
