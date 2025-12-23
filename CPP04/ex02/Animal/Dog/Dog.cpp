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
	_brain = new Brain;
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string name) : Animal("Dog"), _name(name)
{
	_brain = new Brain;
	std::cout << "Dog constructor called for " << name << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), _name(other._name)
{
	_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructor called for " << other._name << std::endl;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog destructor called for " << _name << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		std::cout << "Dog assignment operator called" << std::endl;
		this->_name = other._name;
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "The dog is barking ..." << std::endl;
}
