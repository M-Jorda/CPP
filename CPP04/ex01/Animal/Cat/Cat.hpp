/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:32:40 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/23 16:15:28 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Cat.h"

class Cat : public Animal
{
	private :
		std::string	_name;
		Brain		*_brain;

	public :
		Cat(void);
		Cat(std::string name);
		Cat(const Cat &other);
		~Cat(void);

		Cat		&operator=(const Cat &other);
		void	makeSound() const;
};

#endif
