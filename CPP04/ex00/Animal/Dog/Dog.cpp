/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:19:06 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 16:25:46 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"), _name("Rex")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string name) : Animal("Dog"), _name(name)
{
	std::cout << "Dog name constructor called for " << name << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), _name(other._name)
{
	std::cout << "Creation of a copy of " << other._name << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called for " << _name << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		std::cout << "Creation by assignation of a copy of " << other._name << std::endl;
		this->_name = other._name;
		this->_type = other._type;
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "The dog is barking ..." << std::endl;
}
