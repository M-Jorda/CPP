/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:57:41 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/20 14:59:00 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include "HumanB.h"

class HumanB
{
	private:
		Weapon		*_weapon;
		std::string	_name;

	public:
		HumanB(std::string name);
		~HumanB(void);

		void	attack(void);
		void	setWeapon(Weapon &weapon);
};

#endif
