/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:15:04 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 12:15:04 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*	_brain;

	public:
		Dog();
		Dog(const Dog& other);
		Dog&	operator=(const Dog& other);
		~Dog();

		void	makeSound() const;
		Brain*	getBrain() const;
};
