#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

class	RobotomyRequestForm
{
	private:
		type _name;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(type name);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();
};

#endif

