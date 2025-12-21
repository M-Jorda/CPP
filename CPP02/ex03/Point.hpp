/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:08:13 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/21 17:45:29 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Point.h"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const &other);
		~Point(void);

		Point	&operator=(Point const &other);
		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const p);

#endif
