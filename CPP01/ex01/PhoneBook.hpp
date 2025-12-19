/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:31:56 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/19 12:08:23 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <stdlib.h>
# include <sstream>
# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact _contact[8];
		int		_contactCount;
		int		_oldest;

	public:
		PhoneBook(void);

		~PhoneBook(void);

		Contact	getContact(int index)	const;
		int		getContactCount(void)	const;
		int		getOldest(void)			const;

		void	SetContact(Contact contact);
		void	setOldest(int index);

		std::string	formatColumn(std::string str) const;
		void		displayInfo(int index) const;
		int			displayContacts(void);	
		void		displayHelp(void);
};

#endif