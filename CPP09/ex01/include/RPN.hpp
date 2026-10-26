#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <list>
# include <string>
# include <stdexcept>

class	RPN
{
	public:
		// Default constructor: the class holds no state.
		RPN();
		// Copy constructor: nothing to copy.
		// @param other  instance to copy
		RPN(const RPN &other);
		// Assignment operator: nothing to copy.
		// @param other  instance to copy
		// @return       *this
		RPN &operator=(const RPN &other);
		// Destructor: nothing to free.
		~RPN();

		// Evaluate a Reverse Polish Notation expression with a local stack.
		// Throws ExpressionError on an invalid token, missing operands,
		// operands left over, a division by zero or an int overflow.
		// @param str  tokens separated by whitespace: single digits,
		//             optionally negative, and the operators + - * /
		// @return     result of the expression
		int	calculate(std::string const &str) const;

		// Thrown on a wrong command line: no argument, several arguments,
		// or an empty / blank argument.
		// Constructors: default message (usage line), or a custom one.
		// @param msg    custom message returned by what()
		// @param other  exception to copy (copy constructor / operator=)
		class	UsageError : public std::runtime_error
		{
			public:
				UsageError();
				UsageError(std::string const &msg);
				UsageError(UsageError const &other);
				UsageError &operator=(UsageError const &other);
				~UsageError() throw();
		};

		// Thrown when the expression cannot be evaluated.
		// Constructors: default message ("invalid expression"), or a
		// custom one naming the cause.
		// @param msg    custom message returned by what()
		// @param other  exception to copy (copy constructor / operator=)
		class	ExpressionError : public std::runtime_error
		{
			public:
				ExpressionError();
				ExpressionError(std::string const &msg);
				ExpressionError(ExpressionError const &other);
				ExpressionError &operator=(ExpressionError const &other);
				~ExpressionError() throw();
		};

		// Operand stack; std::list keeps std::deque, the default, for ex02.
		typedef std::stack<int, std::list<int> > Stack;
};

#endif
