/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 06:35:56 by jjorda            #+#    #+#             */
/*   Updated: 2026/01/13 16:27:24 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//                                  (DE)CONST

Contact::Contact(void) {}

Contact::Contact(const Contact& other)
{
	_firstName = other._firstName;
	_lastName = other._lastName;
	_nickName = other._nickName;
	_darkestSecret = other._darkestSecret;
	_phoneNumber = other._phoneNumber;
}

Contact &Contact::operator=(const Contact &other)
{
	if (this != &other)
	{
		_firstName = other._firstName;
		_lastName = other._lastName;
		_nickName = other._nickName;
		_darkestSecret = other._darkestSecret;
		_phoneNumber = other._phoneNumber;
	}
	return (*this);
}

Contact::~Contact(void)
{}

//                                   GETTER

std::string Contact::getFirstName(void) const
{
	return (_firstName);
}

std::string	Contact::getLastName(void) const
{
	return (_lastName);
}

std::string	Contact::getNickName(void) const
{
	return (_nickName);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (_darkestSecret);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (_phoneNumber);
}

//                                   SETTER

void	Contact::setFirstName(std::string firstName)
{
	_firstName = firstName;
}

void	Contact::setLastName(std::string lastName)
{
	_lastName = lastName;
}

void	Contact::setNickName(std::string nickName)
{
	_nickName = nickName;
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
	_darkestSecret = darkestSecret;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	_phoneNumber = phoneNumber;
}
