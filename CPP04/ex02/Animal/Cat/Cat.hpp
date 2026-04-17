/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:32:40 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 12:32:40 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*	_brain;

	public:
		Cat();
		Cat(const Cat& other);
		Cat&	operator=(const Cat& other);
		~Cat();

		void	makeSound() const;
		Brain*	getBrain() const;
};
