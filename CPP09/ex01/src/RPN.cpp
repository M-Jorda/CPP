#include "RPN.hpp"

#include <sstream>
#include <cctype>

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

static int	popValue(std::stack<int, std::list<int> > &stack)
{
	int	v = stack.top();
	stack.pop();
	return (v);
}

static void	pushNumber(std::stack<int, std::list<int> > &stack, std::string const &token)
{
	int num;

	if (token.size() == 2)
		num = (token[1] - '0') * -1;
	else
		num = token[0] - '0';
	stack.push(num);
}

static void	applyOperator(std::stack<int, std::list<int> > &stack, std::string const &token)
{
	if (stack.size() > 1)
	{
		int	v2 = popValue(stack);
		int v1 = popValue(stack);
		int r;

		switch (token[0])
		{
		case '-':
			r = v1 - v2;
			break ;
		case '+':
			r = v1 + v2;
			break ;
		case '/':
			r = v1 / v2;
			break ;
		case '*':
			r = v1 * v2;
			break ;
		default :
			throw (RPN::ExpressionError("Unknown operator"));
		}
		stack.push(r);
	}
	else
		throw (RPN::ExpressionError("not enough operands"));
}

int	RPN::calculate(std::string const &str)
{
	while (!_stack.empty())
		_stack.pop();
	std::istringstream	iss(str);
	std::string			token;
	while (iss >> token)
	{
		if ((token.size() == 2 && token[0] == '-' && std::isdigit((unsigned char) token[1])) 
				|| (token.size() == 1 && std::isdigit((unsigned char) token[0])))
			pushNumber(_stack, token);
		else if (token == "+" || token == "-" || token == "/" || token == "*")
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
