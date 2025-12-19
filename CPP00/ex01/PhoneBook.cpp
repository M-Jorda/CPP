/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:36:44 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/19 15:39:01 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//                                  (DE)CONST

PhoneBook::PhoneBook(void) : _contactCount(0), _oldest(0)
{}

PhoneBook::PhoneBook(const PhoneBook &other)
{
	for (int i = 0; i < 8; i++)
		_contact[i] = other._contact[i];
	_contactCount = other._contactCount;
	_oldest = other._oldest;
}

PhoneBook &PhoneBook::operator=(const PhoneBook &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 8; i++)
			_contact[i] = other._contact[i];
		_contactCount = other._contactCount;
		_oldest = other._oldest;
	}
	return (*this);
}

PhoneBook::~PhoneBook(void)
{}

//                                   GETTER

Contact	PhoneBook::getContact(int index)	const
{
	return (_contact[index]);
}

int	PhoneBook::getContactCount(void)	const
{
	return (_contactCount);
}

int	PhoneBook::getOldest(void)	const
{
	return (_oldest);
}

//                                   SETTER

void	PhoneBook::SetContact(Contact contact)
{
	if (_contactCount == 8)
	{
		_contact[_oldest] = contact;
		_oldest++;
		if (_oldest == 8)
			_oldest = 0;
		// for (int i = 0; i < 7; i++)
		// 	_contact[i] = _contact[i + 1];
		// _contact[7] = contact;
	}
	else
		_contact[_contactCount++] = contact;
}

void	PhoneBook::setOldest(int index)
{
	_oldest = index;
}


std::string	PhoneBook::formatColumn(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (std::string(10 - str.length(), ' ') + str);
}

void	PhoneBook::displayInfo(int index) const
{
	std::cout << "Index:		" << index << std::endl;
	std::cout << "First name:	" << getContact(index).getFirstName() << std::endl;
	std::cout << "Second name:	" << getContact(index).getLastName() << std::endl;
	std::cout << "Nickname:	" << getContact(index).getNickName() << std::endl;
	std::cout << "Phone number:	" << getContact(index).getNumber() << std::endl;
	std::cout << "Darkest secret:	" << getContact(index).getDarkestSecret() << std::endl;
}

int	PhoneBook::displayContacts(void)
{
	if (_contactCount == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return (0);
	}
	std::cout << "INDEX     |";
	std::cout << "F_NAME    |";
	std::cout << "S_NAME    |";
	std::cout << "N_NAME    |" << std::endl;
	for (int i = 0; i < _contactCount; i++)
	{
		std::cout << i << "         |";
		std::cout << formatColumn(_contact[i].getFirstName()) << "|";
		std::cout << formatColumn(_contact[i].getLastName()) << "|";
		std::cout << formatColumn(_contact[i].getNickName()) << "|" << std::endl;
	}
	return (1);
}

void	PhoneBook::displayHelp(void)
{
	std::cout << "Useful keys :" << std::endl;
	std::cout << "- 'ADD' for adding a contact." << std::endl;
	std::cout << "- 'SEARCH' for searching a contact." << std::endl;
	std::cout << "- 'EXIT' for exiting the program." << std::endl;
	std::cout << "- 'HELP' to get this message." << std::endl;
}
