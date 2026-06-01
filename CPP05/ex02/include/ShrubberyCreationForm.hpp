#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <exception>
# include <fstream>

# include "AForm.hpp"

class	Bureaucrat;

class	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		class	FileNotCreatedException : public std::exception
		{
			public:
				virtual const char* what()	const throw();
		};

	protected:
		void	_executeAction(Bureaucrat const & executor) const override;

	private:
		std::string _target;
};

#endif
