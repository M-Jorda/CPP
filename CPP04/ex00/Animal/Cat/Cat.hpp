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

# define NAME_CAT	"Cat"
# define MSG_CAT	"Meow!"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& other);
		Cat&	operator=(const Cat& other);
		~Cat();

		void	makeSound() const;
};
