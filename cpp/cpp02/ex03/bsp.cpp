/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy-kankiya <georgy-kankiya@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:01:43 by gkankia           #+#    #+#             */
/*   Updated: 2025/07/17 13:30:28 by georgy-kank      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Fixed	signedArea(Point const a, Point const b, Point const point)
{
	float	first = ((point.getX().toFloat() - b.getX().toFloat()) * (a.getY().toFloat() - b.getY().toFloat()));
	float	second = ((a.getX().toFloat() - b.getX().toFloat()) * (point.getY().toFloat() - b.getY().toFloat()));

	return (Fixed(first - second));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	ab = signedArea(a, b, point);
	Fixed	bc = signedArea(b, c, point);
	Fixed	ca = signedArea(c, a, point);

	if (ab > 0 && bc > 0 && ca > 0)
		return (true);
	if (ab < 0 && bc < 0 && ca < 0)
		return (true);
	return (false);
}