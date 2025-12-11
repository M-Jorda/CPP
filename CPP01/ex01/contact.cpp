/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 06:35:56 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/11 06:53:25 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

//                                  (DE)CONST

Contact::Contact(void) : _firstName(""), _secondName(""), _nickName(""),
	_darkestSecret(""), _number(0)
{
	std::cout << "Contact created" << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Contact replaced" << std::endl;
}

//                                   GETTER

std::string Contact::getFirstName(void) const
{
	return (_firstName);
}

std::string	Contact::getSecondName(void) const
{
	return (_secondName);
}

std::string	Contact::getNickName(void) const
{
	return (_nickName);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (_darkestSecret);
}

int	Contact::getNumber(void) const
{
	return (_number);
}

//                                   SETTER

void	Contact::setFirstName(std::string firstName)
{
	_firstName = firstName;
}

void	Contact::setSecondName(std::string secondName)
{
	_secondName = secondName;
}

void	Contact::setNickName(std::string nickName)
{
	_nickName = nickName;
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
	_darkestSecret = darkestSecret;
}

void	Contact::setNumber(int number)
{
	_number = number;
}

void	displayInfo(void) const
{
	std::cout
}
