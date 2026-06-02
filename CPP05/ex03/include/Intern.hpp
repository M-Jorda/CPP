#ifndef INTERN_HPP
# define INTERN_HPP

class	Intern
{
	public:
		Intern();
		Intern(type name);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

	private:
		type _name;
};

#endif
