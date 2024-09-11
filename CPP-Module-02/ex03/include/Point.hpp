/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:48:06 by gabe              #+#    #+#             */
/*   Updated: 2024/09/12 00:23:17 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const Fixed &x, const Fixed &y);
		Point(const Point &other);
		~Point();
		Point &operator=(const Point &other);
		Fixed getX(void) const;
		Fixed getY(void) const;
	private:
		const Fixed _x;
		const Fixed _y;
};


bool bsp(Point const a, Point const b, Point const c, Point const p);


#endif