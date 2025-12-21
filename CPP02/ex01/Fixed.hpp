/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:29:21 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/21 12:39:20 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include "Fixed.h"

class Fixed
{
	private :
		int					_rawBits;
		static const int	_fractionalBits = 8;

	public :
		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &other);
		~Fixed(void);

		Fixed	&operator=(const Fixed &other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);

#endif