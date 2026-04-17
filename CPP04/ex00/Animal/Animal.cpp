/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:47:48 by jjorda            #+#    #+#             */
/*   Updated: 2026/04/17 20:44:02 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type(NAME_ANIMAL)
{
	cout << NAME_ANIMAL << MSG_DF_CONS << endl;
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	cout << NAME_ANIMAL << MSG_CP_CONS << endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		_type = other._type;
	return *this;
}

Animal::~Animal()
{
	cout << NAME_ANIMAL << MSG_DES << endl;
}

void Animal::makeSound() const
{
	cout << MSG_ANIMAL << endl;
}

std::string Animal::getType() const
{
	return _type;
}

std::ostream& operator<<(std::ostream& os, const Animal& other)
{
	os << other.getType();
	return os;
}
