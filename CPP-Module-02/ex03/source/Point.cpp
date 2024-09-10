/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:56:03 by gabe              #+#    #+#             */
/*   Updated: 2024/09/10 20:36:00 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y) {}

Point::Point(const Point &other) {}

Point& Point::operator=(const Point &other)
{
	if (this != &other)
	{
		const_cast<Fixed&>(_x) = other._x;
		const_cast<Fixed&>(_y) = other._y;
	}
	return (*this);
}

Point::~Point() {}

Fixed Point::getX(void) const { return _x;}

Fixed Point::getY(void) const { return _y;}
