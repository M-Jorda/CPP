#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

class	PresidentialPardonForm
{
	private:
		type _name;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(type name);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();
};

#endif

