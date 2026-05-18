/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:40:54 by jjorda            #+#    #+#             */
/*   Updated: 2026/05/18 18:33:00 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

# include "Form.hpp"

class	Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;

		void	incGrade();
		void	decGrade();

		void	signForm(Bureaucrat b, Form f);

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);

#endif

