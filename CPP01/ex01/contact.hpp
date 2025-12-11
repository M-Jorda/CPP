/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 06:24:39 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/11 06:51:25 by jjorda           ###   ########.fr       */
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
		std::string	_secondName;
		std::string	_nickName;
		std::string	_darkestSecret;
		int			_number;

	public:
		Contact(void);
		
		~Contact(void);
		
		std::string	getFirstName(void)		const;
		std::string	getSecondName(void)		const;
		std::string	getNickName(void)		const;
		std::string	getDarkestSecret(void)	const;
		int			getNumber(void)			const;

		void		setFirstName(std::string firstName);
		void		setSecondName(std::string secondName);
		void		setNickName(std::string nickName);
		void		setDarkestSecret(std::string darkestSecret);
		void		setNumber(int number);
		
		void		displayInfo(void) const;
		
};

#endif