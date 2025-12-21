/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 15:30:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/21 15:30:00 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	std::cout << "===== CONSTRUCTEURS =====" << std::endl;
	Fixed a;
	Fixed b(10);
	Fixed c(42.42f);
	Fixed d(b);
	
	std::cout << "\n===== AFFICHAGE =====" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	
	std::cout << "\n===== CONVERSIONS =====" << std::endl;
	std::cout << "b.toInt() = " << b.toInt() << std::endl;
	std::cout << "b.toFloat() = " << b.toFloat() << std::endl;
	std::cout << "c.toInt() = " << c.toInt() << std::endl;
	std::cout << "c.toFloat() = " << c.toFloat() << std::endl;
	
	std::cout << "\n===== AFFECTATION =====" << std::endl;
	a = c;
	std::cout << "a = c; a = " << a << std::endl;
	
	std::cout << "\n===== OPERATEURS DE COMPARAISON =====" << std::endl;
	Fixed x(5);
	Fixed y(10);
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "x > y ? " << (x > y) << std::endl;
	std::cout << "x < y ? " << (x < y) << std::endl;
	std::cout << "x >= y ? " << (x >= y) << std::endl;
	std::cout << "x <= y ? " << (x <= y) << std::endl;
	std::cout << "x == y ? " << (x == y) << std::endl;
	std::cout << "x != y ? " << (x != y) << std::endl;
	
	std::cout << "\n===== OPERATEURS ARITHMETIQUES =====" << std::endl;
	Fixed num1(10);
	Fixed num2(3);
	std::cout << "num1 = " << num1 << ", num2 = " << num2 << std::endl;
	std::cout << "num1 + num2 = " << (num1 + num2) << std::endl;
	std::cout << "num1 - num2 = " << (num1 - num2) << std::endl;
	std::cout << "num1 * num2 = " << (num1 * num2) << std::endl;
	std::cout << "num1 / num2 = " << (num1 / num2) << std::endl;
	
	std::cout << "\n===== PRE-INCREMENTATION =====" << std::endl;
	Fixed pre(5);
	std::cout << "pre = " << pre << std::endl;
	std::cout << "++pre = " << (++pre) << std::endl;
	std::cout << "pre = " << pre << std::endl;
	
	std::cout << "\n===== POST-INCREMENTATION =====" << std::endl;
	Fixed post(5);
	std::cout << "post = " << post << std::endl;
	std::cout << "post++ = " << (post++) << std::endl;
	std::cout << "post = " << post << std::endl;
	
	std::cout << "\n===== PRE-DECREMENTATION =====" << std::endl;
	Fixed predec(5);
	std::cout << "predec = " << predec << std::endl;
	std::cout << "--predec = " << (--predec) << std::endl;
	std::cout << "predec = " << predec << std::endl;
	
	std::cout << "\n===== POST-DECREMENTATION =====" << std::endl;
	Fixed postdec(5);
	std::cout << "postdec = " << postdec << std::endl;
	std::cout << "postdec-- = " << (postdec--) << std::endl;
	std::cout << "postdec = " << postdec << std::endl;
	
	std::cout << "\n===== OPERATEURS MIN/MAX (NON-CONST) =====" << std::endl;
	Fixed min1(7);
	Fixed min2(3);
	std::cout << "min1 = " << min1 << ", min2 = " << min2 << std::endl;
	std::cout << "Fixed::min(min1, min2) = " << Fixed::min(min1, min2) << std::endl;
	std::cout << "Fixed::max(min1, min2) = " << Fixed::max(min1, min2) << std::endl;
	
	std::cout << "\n===== OPERATEURS MIN/MAX (CONST) =====" << std::endl;
	const Fixed cmin1(7);
	const Fixed cmin2(3);
	std::cout << "cmin1 = " << cmin1 << ", cmin2 = " << cmin2 << std::endl;
	std::cout << "Fixed::min(cmin1, cmin2) = " << Fixed::min(cmin1, cmin2) << std::endl;
	std::cout << "Fixed::max(cmin1, cmin2) = " << Fixed::max(cmin1, cmin2) << std::endl;
	
	std::cout << "\n===== OPERATIONS COMPLEXES =====" << std::endl;
	Fixed p(2.5f);
	Fixed q(4.5f);
	std::cout << "p = " << p << ", q = " << q << std::endl;
	std::cout << "p * q = " << (p * q) << std::endl;
	std::cout << "p / q = " << (p / q) << std::endl;
	std::cout << "(p + q) * 2 = " << ((p + q) * Fixed(2)) << std::endl;
	
	std::cout << "\n===== CHAINAGE D'OPERATEURS =====" << std::endl;
	Fixed chain(1);
	std::cout << "chain = " << chain << std::endl;
	std::cout << "++chain = " << ++chain << ", ++chain = " << ++chain << ", ++chain = " << ++chain << std::endl;
	std::cout << "chain = " << chain << std::endl;
	
	std::cout << "\n===== FIN DES TESTS =====" << std::endl;
	
	return 0;
}
