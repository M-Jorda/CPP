#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::stack<int, std::list<int> > stack) : _stack(stack) {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN&	RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	return (*this);
}

RPN::~RPN() {}

int	RPN::calculate(std::string str)
{
	int	r = 0;
	(void) str;
	return (r);
}

RPN::UsageError::UsageError() : std::runtime_error("Error: usage: ./RPN \"<expression>\"") {}

RPN::UsageError::UsageError(std::string const &msg) : std::runtime_error(msg) {}

RPN::UsageError::UsageError(UsageError const &other) : std::runtime_error(other) {}

RPN::UsageError	&RPN::UsageError::operator=(UsageError const &other)
{
	std::runtime_error::operator=(other);
	return (*this);
}

RPN::UsageError::~UsageError() throw() {}


RPN::ExpressionError::ExpressionError() : std::runtime_error("Error: expression error.") {}

RPN::ExpressionError::ExpressionError(std::string const &msg) : std::runtime_error(msg) {}

RPN::ExpressionError::ExpressionError(ExpressionError const &other) : std::runtime_error(other) {}

RPN::ExpressionError	&RPN::ExpressionError::operator=(ExpressionError const &other)
{
	std::runtime_error::operator=(other);
	return (*this);
}

RPN::ExpressionError::~ExpressionError() throw() {}
