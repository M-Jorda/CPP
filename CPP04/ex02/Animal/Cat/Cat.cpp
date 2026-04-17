/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:35:21 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 12:35:21 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain())
{
	_type = NAME_CAT;
	cout << NAME_CAT << MSG_DF_CONS << endl;
}

Cat::Cat(const Cat& other) : Animal(other), _brain(new Brain(*other._brain))
{
	cout << NAME_CAT << MSG_CP_CONS << endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	cout << NAME_CAT << MSG_DES << endl;
}

void Cat::makeSound() const
{
	cout << MSG_CAT << endl;
}

Brain* Cat::getBrain() const
{
	return _brain;
}
