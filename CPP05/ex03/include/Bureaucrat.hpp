/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:40:54 by jjorda            #+#    #+#             */
/*   Updated: 2026/05/27 10:15:53 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

# include "Macro.hpp"
# include "AForm.hpp"

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		void		signForm(AForm &form);
		void		executeForm(AForm const & form) const;

		void	incGrade();
		void	decGrade();

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

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);

#endif

