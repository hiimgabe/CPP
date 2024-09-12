/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:40:55 by gabe              #+#    #+#             */
/*   Updated: 2024/09/12 14:39:26 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

static Fixed abs(Fixed x) { return (x = x < 0 ? x * -1 : x); }

Fixed triangleArea(Point const a, Point const b, Point const c)
{
	Fixed area;

	area = (a.getX() * (b.getY() - c.getY()) +
			b.getX() * (c.getY() - a.getY()) +
			c.getX() * (a.getY() - b.getY())) / 2;
	return (abs(area));
}

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed abcArea = triangleArea(a, b, c);
	Fixed pabArea = triangleArea(p, a, b);
	Fixed pbcArea = triangleArea(p, b, c);
	Fixed pcaArea = triangleArea(p, c, a);

	if (pabArea == 0 || pbcArea == 0 || pcaArea == 0)
		return (false);
	return ((pabArea + pbcArea + pcaArea) == abcArea);
}


/*
	triangle area = ABS [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2) ] / 2 
*/