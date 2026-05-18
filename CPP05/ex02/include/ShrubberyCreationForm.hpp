#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

class	ShrubberyCreationForm
{
	private:
		type _name;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(type name);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
};

#endif

