/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy-kankiya <georgy-kankiya@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:08:06 by gkankia           #+#    #+#             */
/*   Updated: 2025/08/27 14:35:02 by georgy-kank      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0) {}

Point::~Point() {}

Point::Point(float const x, float const y) : x(x), y(y) {}

Point::Point(Point const &src) 
{
	*this = src;
}

Point&	Point::operator=(Point const &src)
{
	if (this != &src)
        new (this) Point(src.getX().toFloat(), src.getY().toFloat());
    return (*this);
}

Fixed const Point::getX() const
{
    return (this->x);
}

Fixed const Point::getY() const
{
    return (this->y);
}