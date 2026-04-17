/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:24:08 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 14:24:08 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include "Polymorphism.hpp"

class Brain
{
	public:
		std::string	ideas[100];

		Brain();
		Brain(const Brain& other);
		Brain&		operator=(const Brain& other);
		~Brain();

		void		setIdea(int index, const std::string& idea);
		std::string	getIdea(int index) const;
};
