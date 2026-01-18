/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:35:21 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 16:25:46 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"), _name("Mistigris")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string name) : Animal("Cat"), _name(name)
{
	std::cout << "Cat name constructor called for " << name << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), _name(other._name)
{
	std::cout << "Creation of a copy of " << other._name << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called for " << _name << std::endl;
}

Cat		&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		std::cout << "Creation by assignation of a copy of " << other._name << std::endl;
		this->_name = other._name;
		this->_type = other._type;
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "The cat is meowing ..." << std::endl;
}
