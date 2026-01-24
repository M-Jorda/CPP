/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 10:34:14 by jjorda            #+#    #+#             */
/*   Updated: 2026/01/24 17:46:47 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <iostream>
# include <string>

# define DEBUG		"[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
# define INFO		"[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
# define WARNING	"[ WARNING ]\nI think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month."
# define ERROR		"[ ERROR ]\nThis is unacceptable! I want to speak to the manager now."
# define COMPLAIN	"[ Probably complaining about insignificant problems ]"

struct	s_complainLevel
{
	std::string	name;
	int			level;
};

enum	e_Level
{
	LVL_D,
	LVL_I,
	LVL_W,
	LVL_E,
	LVL_U
};

#endif
