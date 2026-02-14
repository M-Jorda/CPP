/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:15:04 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 16:41:56 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Dog.h"

class Dog : public Animal
{
	private :
		std::string	_name;
		Brain		*_brain;

	public :
		Dog(void);
		Dog(std::string name);
		Dog(const Dog &other);
		 virtual ~Dog(void);

		Dog				&operator=(const Dog &other);
		virtual void	makeSound()						const;
};

#endif
