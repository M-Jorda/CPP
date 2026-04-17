/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:06:27 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 14:06:27 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = NAME_WRONGCAT;
	cout << NAME_WRONGCAT << MSG_DF_CONS << endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	cout << NAME_WRONGCAT << MSG_CP_CONS << endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat()
{
	cout << NAME_WRONGCAT << MSG_DES << endl;
}

void WrongCat::makeSound() const
{
	cout << MSG_WRONGCAT << endl;
}
