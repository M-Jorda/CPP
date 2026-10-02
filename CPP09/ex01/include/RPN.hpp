#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <list>
# include <string>
# include <stdexcept>


class	RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		int	calculate(std::string str);

		class	UsageError : public std::runtime_error
		{
			public:
				UsageError();
				UsageError(std::string const &msg);
				UsageError(UsageError const &other);
				UsageError &operator=(UsageError const &other);
				~UsageError() throw();
		};

		class	ExpressionError : public std::runtime_error
		{
			public:
				ExpressionError();
				ExpressionError(std::string const &msg);
				ExpressionError(ExpressionError const &other);
				ExpressionError &operator=(ExpressionError const &other);
				~ExpressionError() throw();
		};

	private:
		std::stack<int, std::list<int> >	_stack;
};

#endif
