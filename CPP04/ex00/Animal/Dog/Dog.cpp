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

Dog::Dog() : Animal()
{
	_type = NAME_DOG;
	cout << NAME_DOG << MSG_DF_CONS << endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	cout << NAME_DOG << MSG_CP_CONS << endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Dog::~Dog()
{
	cout << NAME_DOG << MSG_DES << endl;
}

void Dog::makeSound() const
{
	cout << MSG_DOG << endl;
}
