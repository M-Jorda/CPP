/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:25:17 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/21 17:42:29 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	ft_getArea(Point a, Point b, Point c)
{
	Fixed	aVector = (b.getX() - a.getX()) * (c.getY() - a.getY());
	Fixed	bVector = (c.getX() - a.getX()) * (b.getY() - a.getY());
	Fixed	res = (aVector - bVector) / 2;
	if (res < 0)
		res = res * Fixed(-1);
	return (res);
}

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed	area_abc;
	Fixed	area_pab;
	Fixed	area_pbc;
	Fixed	area_pca;
	
	area_abc = ft_getArea(a, b, c);
	area_pab = ft_getArea(p, a, b);
	area_pbc = ft_getArea(p, b, c);
	area_pca = ft_getArea(p, c, a);

	if (area_pab == 0 || area_pbc == 0 || area_pca == 0)
		return (false);
	return (area_abc == (area_pab + area_pbc + area_pca));
}
