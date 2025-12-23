/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 14:24:08 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 15:20:02 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Brain.h"

class Brain
{
	protected :
		std::string	_ideas[100];
		int			_CountIdea;

	public :
		Brain(void);
		Brain(std::string idea);
		Brain(const Brain &other);
		~Brain(void);

		Brain		&operator=(const Brain &other);
		void		setideas(std::string *ideas, int countIdea);
		void		setIdea(std::string);
		std::string	getIdea(int idea);
		std::string	*getIdeas(void);
};

#endif
