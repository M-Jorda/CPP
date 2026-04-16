/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:24:16 by jjorda            #+#    #+#             */
/*   Updated: 2026/04/16 21:48:37 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public :
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &other);
		virtual	~ScavTrap(void);

		ScavTrap	&operator=(const ScavTrap &other);
		void		attack(const std::string& target);
		void 		guardGate();
};

#endif
