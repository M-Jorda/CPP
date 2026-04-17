/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorphism.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 20:08:41 by jjorda            #+#    #+#             */
/*   Updated: 2026/04/17 20:08:41 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

using std::cout;
using std::endl;

# define MSG_CONS			" constructor called"
# define MSG_DES			" destructor called"
# define MSG_DF_CONS		" default" MSG_CONS
# define MSG_CP_CONS		" copy" MSG_CONS

# define NAME_ANIMAL		"Animal"
# define NAME_CAT			"Cat"
# define NAME_DOG			"Dog"
# define NAME_BRAIN			"Brain"
# define NAME_WRONGANIMAL	"WrongAnimal"
# define NAME_WRONGCAT		"WrongCat"

# define MSG_ANIMAL			"..."
# define MSG_CAT			"Meow!"
# define MSG_DOG			"Woof!"
# define MSG_WRONGANIMAL	"WrongAnimal sound..."
# define MSG_WRONGCAT		"WrongMeow!"
