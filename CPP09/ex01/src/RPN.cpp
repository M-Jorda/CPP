#include "RPN.hpp"

#include <sstream>
#include <cctype>
#include <climits>

#define INVEXPR	"invalid expression"

RPN::RPN() {}

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

static int	popValue(RPN::Stack &stack)
{
	int	v = stack.top();
	stack.pop();
	return (v);
}

static void	pushNumber(RPN::Stack &stack, std::string const &token)
{
	int num;

	if (token.size() == 2)
		num = (token[1] - '0') * -1;
	else
		num = token[0] - '0';
	stack.push(num);
}

static void	applyOperator(RPN::Stack &stack, std::string const &token)
{
	if (stack.size() > 1)
	{
		// v2 before v1, because of LIFO
		long	v2 = popValue(stack);
		long	v1 = popValue(stack);
		long	r;

		switch (token[0])
		{
		case '-':
			r = v1 - v2;
			break ;
		case '+':
			r = v1 + v2;
			break ;
		case '/':
			if (v2 == 0)
				throw (RPN::ExpressionError("division by zero"));
			r = v1 / v2;
			break ;
		case '*':
			r = v1 * v2;
			break ;
		default :
			throw (RPN::ExpressionError("Unknown operator"));
		}
		if (r > INT_MAX || r < INT_MIN)
			throw (RPN::ExpressionError("integer overflow"));
		stack.push(static_cast<int>(r));
	}
	else
		throw (RPN::ExpressionError("not enough operands"));
}

static bool	isNumber(std::string const &token)
{
	if ((token.size() == 2 && token[0] == '-' && std::isdigit((unsigned char) token[1])) 
			|| (token.size() == 1 && std::isdigit((unsigned char) token[0])))
		return (true);
	return (false);
}

static bool	isOperator(std::string const &token)
{
	if (token == "+" || token == "-" || token == "/" || token == "*")
		return (true);
	return (false);
}

int	RPN::calculate(std::string const &str)
{
	while (!_stack.empty())
		_stack.pop();
	std::istringstream	iss(str);
	std::string			token;
	while (iss >> token)
	{
		if (isNumber(token))
			pushNumber(_stack, token);
		else if (isOperator(token))
			applyOperator(_stack, token);
		else
			throw (ExpressionError("invalid token \"" + token + "\""));
	}
	if (_stack.size() != 1)
		throw (ExpressionError(INVEXPR));
	return (_stack.top());
}

RPN::UsageError::UsageError() : std::runtime_error("usage: ./RPN \"<expression>\"") {}

RPN::UsageError::UsageError(std::string const &msg) : std::runtime_error(msg) {}

RPN::UsageError::UsageError(UsageError const &other) : std::runtime_error(other) {}

RPN::UsageError	&RPN::UsageError::operator=(UsageError const &other)
{
	std::runtime_error::operator=(other);
	return (*this);
}

RPN::UsageError::~UsageError() throw() {}


RPN::ExpressionError::ExpressionError() : std::runtime_error(INVEXPR) {}

RPN::ExpressionError::ExpressionError(std::string const &msg) : std::runtime_error(msg) {}

RPN::ExpressionError::ExpressionError(ExpressionError const &other) : std::runtime_error(other) {}

RPN::ExpressionError	&RPN::ExpressionError::operator=(ExpressionError const &other)
{
	std::runtime_error::operator=(other);
	return (*this);
}

RPN::ExpressionError::~ExpressionError() throw() {}
