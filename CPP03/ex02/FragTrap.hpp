/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 08:13:41 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 08:38:01 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "FragTrap.h"

class FragTrap : public ClapTrap
{
	public :
		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap(const FragTrap &other);
		~FragTrap(void);

		FragTrap	&operator=(const FragTrap &other);
		void		highFivesGuys(void);
};

#endif
