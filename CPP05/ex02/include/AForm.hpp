#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <exception>

class	Bureaucrat;

class	AForm
{
	public:
		AForm();
		AForm(std::string name, int _gradeToSign, int _gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();

		std::string	getName() const;
		int			getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		
		void	beSigned(Bureaucrat &b);
		void	execute(Bureaucrat const & executor) const;

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

		class	FormNotSignedException : public std::exception
		{
			public:
				virtual const char*	what()	const throw();
		};

	protected:
		virtual void	_executeAction(Bureaucrat const & executor) const = 0;

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const AForm& other);

#endif

