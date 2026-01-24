/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 00:00:00 by                   #+#    #+#             */
/*   Updated: 2026/01/18 17:28:21 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	ft_print(std::string message)
{
	std::cout << message;
}

std::string	ft_add_champ(std::string field)
{
	std::string	str;

	while (1)
	{
		ft_print(field);
		if (!std::getline(std::cin, str))
			exit(1);
		if (!str.empty())
			break ;
		ft_print("Every field must be filled.\n");
		
	}
	return (str);
}

std::string	ft_add_number()
{
	std::string	num;

	while (1)
	{
		ft_print("Phone number: ");
		if (!std::getline(std::cin, num))
			exit(1);
		if (!num.empty())
			break ;
		ft_print("The phone number can't be empty.\n");
	}
	return (num);
}

Contact	ft_add_contact()
{
	Contact		contact;

	contact.setFirstName(ft_add_champ("First name: "));
	contact.setLastName(ft_add_champ("Last name: "));
	contact.setNickName(ft_add_champ("Nickname: "));
	contact.setPhoneNumber(ft_add_number());
	contact.setDarkestSecret(ft_add_champ("Darkest secret: "));
	return (contact);
}

void	ft_search(PhoneBook &pb)
{
	int		index;
	std::string	input;

	while (1)
	{
		ft_print("index of the contact: ");
		if (!std::getline(std::cin, input))
			return ;
		if (input.empty())
		{
			ft_print("Invalid input.\n");
			continue ;
		}
		std::stringstream ss(input);
		// index = atoi(input.c_str());
		if ((ss >> index) && ss.eof() && index >= 0 && index < pb.getContactCount())
		{
			pb.displayInfo(index);
			break ;
		}
		ft_print("The index must be an existing one.\n");
	}
}

int	main(void)
{
	PhoneBook	pb;

	while (1)
	{
		std::string cmd;
		ft_print("Enter your command or HELP: ");
		if (!std::getline(std::cin, cmd))
			break ;
		if (cmd == "EXIT")
			break ;
		else if (cmd == "SEARCH")
		{
			if (pb.displayContacts())	
				ft_search(pb);
		}
		else if (cmd == "HELP")
			pb.displayHelp();
		else if (cmd == "ADD")
		{
			pb.SetContact(ft_add_contact());
			std::cout << "Contact added successfully." << std::endl;
		}
	}

	return (0);
}
