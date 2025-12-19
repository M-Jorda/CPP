/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 06:24:39 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/19 15:24:31 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class	Contact
{
	private:

		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_darkestSecret;
		long		_number;

	public:
		Contact();
		Contact(const Contact &other);
		Contact &operator=(const Contact &other);
		~Contact(void);

		std::string	getFirstName(void)		const;
		std::string	getLastName(void)		const;
		std::string	getNickName(void)		const;
		std::string	getDarkestSecret(void)	const;
		long			getNumber(void)			const;

		void		setFirstName(std::string firstName);
		void		setLastName(std::string lastName);
		void		setNickName(std::string nickName);
		void		setDarkestSecret(std::string darkestSecret);
		void		setNumber(long number);		
};

#endif