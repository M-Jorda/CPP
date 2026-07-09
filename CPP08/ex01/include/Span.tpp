#ifndef SPAN_TPP
# define SPAN_TPP

template <typename Iterator>
void	Span::addNumbers(Iterator begin, Iterator end)
{
	if (span.size() + std::distance(begin, end) > _N)
		throw SpanTooLittle();
	while (begin != end)
		span.push_back(*begin++);
}

#endif
