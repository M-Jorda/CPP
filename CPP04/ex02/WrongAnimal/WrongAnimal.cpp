/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:59:57 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 13:59:57 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type(NAME_WRONGANIMAL)
{
	cout << NAME_WRONGANIMAL << MSG_DF_CONS << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : _type(other._type)
{
	cout << NAME_WRONGANIMAL << MSG_CP_CONS << endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	cout << NAME_WRONGANIMAL << MSG_DES << endl;
}

void WrongAnimal::makeSound() const
{
	cout << MSG_WRONGANIMAL << endl;
}

std::string WrongAnimal::getType() const
{
	return _type;
}

std::ostream& operator<<(std::ostream& os, const WrongAnimal& other)
{
	os << other.getType() << endl;
	return os;
}
