/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:19:06 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 12:19:06 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain())
{
	_type = NAME_DOG;
	cout << NAME_DOG << MSG_DF_CONS << endl;
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain))
{
	cout << NAME_DOG << MSG_CP_CONS << endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	cout << NAME_DOG << MSG_DES << endl;
}

void Dog::makeSound() const
{
	cout << MSG_DOG << endl;
}

Brain* Dog::getBrain() const
{
	return _brain;
}
