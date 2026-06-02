#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

class AForm;

struct FormEntry
{
	std::string	name;
	AForm*		(*create)(std::string);
};

class	Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

		AForm	*makeForm(std::string FormName, std::string target);
};

#endif
