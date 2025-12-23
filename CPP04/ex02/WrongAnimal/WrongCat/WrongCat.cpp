/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:06:27 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 14:06:40 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat"), _name("Mistigris")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string name) : WrongAnimal("WrongCat"), _name(name)
{
	std::cout << "WrongCat name constructor called for " << name << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other), _name(other._name)
{
	std::cout << "Creation of a copy of " << other._name << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called for " << _name << std::endl;
}

WrongCat		&WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		std::cout << "Creation by assignation of a copy of " << other._name << std::endl;
		this->_name = other._name;
		this->_type = other._type;
	}
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "The WrongCat is meowing ..." << std::endl;
}
