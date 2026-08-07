/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy-kankiya <georgy-kankiya@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:08:00 by gkankia           #+#    #+#             */
/*   Updated: 2025/07/17 13:31:03 by georgy-kank      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

#include <iomanip>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int	main()
{
	Point a1(0.0f, 0.0f);
	Point b1(4.0f, 0.0f);
	Point c1(0.0f, 4.0f);
	Point p1(1.0f, 1.0f);
	if (bsp(a1, b1, c1, p1))
		std::cout << "point in a triangle" << std::endl;
	else
		std::cout << "point not in a triangle" << std::endl;


	Point a2(0.0f, 0.0f);
	Point b2(4.0f, 0.0f);
	Point c2(0.0f, 4.0f);
	Point p2(5.0f, 5.0f);
	if (bsp(a2, b2, c2, p2))
		std::cout << "point in a triangle" << std::endl;
	else
		std::cout << "point not in a triangle" << std::endl;


	Point a3(0.0f, 0.0f);
	Point b3(4.0f, 0.0f);
	Point c3(0.0f, 4.0f);
	Point p3(2.0f, 0.0f);
	if (bsp(a3, b3, c3, p3))
		std::cout << "point in a triangle" << std::endl;
	else
		std::cout << "point not in a triangle" << std::endl;

	return (0);
}