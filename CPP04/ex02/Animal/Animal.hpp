/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:38:14 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 16:40:17 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "Animal.h"

class Animal
{
	protected :
		std::string	_type;

	public :
		Animal(void);
		Animal(std::string type);
		Animal(const Animal &other);
		virtual ~Animal(void);

		Animal 			&operator=(const Animal &other);
		virtual void	makeSound()							const = 0;
		std::string		getType(void)						const;
};

#endif
