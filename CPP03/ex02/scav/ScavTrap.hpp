/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:24:16 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/22 18:38:01 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ScavTrap.h"

class ScavTrap : public ClapTrap
{
	public :
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		~ScavTrap(void);

		ScavTrap	&operator=(const ScavTrap &other);
		void		attack(const std::string& target);
		void 		guardGate();
};

#endif
