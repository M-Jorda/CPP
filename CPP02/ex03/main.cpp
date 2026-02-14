/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 17:50:00 by jjorda            #+#    #+#             */
/*   Updated: 2025/12/21 17:50:00 by jjorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main(void)
{
	std::cout << "===== TEST 1 : Point dedans =====" << std::endl;
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);
	Point p1(5, 5);  // Au centre du triangle
	
	std::cout << "Triangle : A(0,0), B(10,0), C(5,10)" << std::endl;
	std::cout << "Point P1(5,5) : " << (bsp(a, b, c, p1) ? "DEDANS" : "DEHORS") << std::endl;
	
	std::cout << "\n===== TEST 2 : Point dehors =====" << std::endl;
	Point p2(15, 15);  // Clairement dehors
	std::cout << "Point P2(15,15) : " << (bsp(a, b, c, p2) ? "DEDANS" : "DEHORS") << std::endl;
	
	std::cout << "\n===== TEST 3 : Point sur une arête =====" << std::endl;
	Point p3(5, 0);  // Sur l'arête AB
	std::cout << "Point P3(5,0) sur arête AB : " << (bsp(a, b, c, p3) ? "DEDANS" : "DEHORS") << std::endl;
	
	std::cout << "\n===== TEST 4 : Point sur un sommet =====" << std::endl;
	Point p4(0, 0);  // Sur le sommet A
	std::cout << "Point P4(0,0) sur sommet A : " << (bsp(a, b, c, p4) ? "DEDANS" : "DEHORS") << std::endl;
	
	std::cout << "\n===== TEST 5 : Point légèrement dedans =====" << std::endl;
	Point p5(3, 2);  // Dedans
	std::cout << "Point P5(3,2) : " << (bsp(a, b, c, p5) ? "DEDANS" : "DEHORS") << std::endl;
	
	std::cout << "\n===== TEST 6 : Triangle différent =====" << std::endl;
	Point t1(0, 0);
	Point t2(4, 0);
	Point t3(2, 4);
	Point p6(2, 1);  // Dedans
	Point p7(2, 3);  // Dedans
	Point p8(0, 1);  // Dehors
	
	std::cout << "Triangle : T1(0,0), T2(4,0), T3(2,4)" << std::endl;
	std::cout << "Point P6(2,1) : " << (bsp(t1, t2, t3, p6) ? "DEDANS" : "DEHORS") << std::endl;
	std::cout << "Point P7(2,3) : " << (bsp(t1, t2, t3, p7) ? "DEDANS" : "DEHORS") << std::endl;
	std::cout << "Point P8(0,1) : " << (bsp(t1, t2, t3, p8) ? "DEDANS" : "DEHORS") << std::endl;
	
	std::cout << "\n===== TEST 7 : Triangle avec valeurs décimales =====" << std::endl;
	Point d1(0.5f, 0.5f);
	Point d2(4.5f, 0.5f);
	Point d3(2.5f, 4.5f);
	Point p9(2.5f, 2.0f);  // Dedans
	
	std::cout << "Triangle : D1(0.5,0.5), D2(4.5,0.5), D3(2.5,4.5)" << std::endl;
	std::cout << "Point P9(2.5,2.0) : " << (bsp(d1, d2, d3, p9) ? "DEDANS" : "DEHORS") << std::endl;
	
	return 0;
}
