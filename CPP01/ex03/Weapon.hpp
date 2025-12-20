/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:56:30 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/20 14:41:38 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include "Weapon.h"

class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(std::string type);
		~Weapon(void);

		std::string	&getType(void);
		void		setType(std::string type);
};

#endif
