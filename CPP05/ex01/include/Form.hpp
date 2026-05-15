#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

# include "Bureaucrat.hpp"

class	Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		Form();
		Form(std::string name, int _isSigned, int _gradeToSign, int _gradeToExecute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		std::string	getName() const;
		int			getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		void	beSigned(Bureaucrat &b);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what()	const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what()	const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& other);

#endif

