/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:47:48 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 16:25:46 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal type constructor called for " << _type << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy from " << other._type << std::endl;
	this->_type = other._type;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal 			&Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		std::cout << "Creation by assignation of a copy" << std::endl;
		this->_type = other._type;
	}
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "the sound of the animal depend his type" << std::endl;
}

std::string		Animal::getType(void) const
{
	return (_type);
}
