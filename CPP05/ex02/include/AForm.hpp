#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>

# include "Bureaucrat.hpp"

class	AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		AForm();
		AForm(std::string name, int _isSigned, int _gradeToSign, int _gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();

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

std::ostream& operator<<(std::ostream& os, const AForm& other);

#endif

