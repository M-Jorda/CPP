/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 10:35:17 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/21 10:42:27 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include "Harl.h"

class Harl
{
	private :
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public :
		void	complain(std::string complain);
};

#endif
