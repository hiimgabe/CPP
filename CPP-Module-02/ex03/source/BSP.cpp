/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:40:55 by gabe              #+#    #+#             */
/*   Updated: 2024/09/12 00:18:55 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
}
/*triangle area = ABS [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2) ] / 2 */
/*
1st
v1 = {c - a} <=> v1 = {c.x - a.x, c.y -c.y}
v2 = {b - a} <=> v2 = {b.x - a.x, b.y - a.y}
v3 = {p - a} <=> v3 = {p.x - a.x, p.y - p.y}

2nd
dot = point1.x * point2.x + point1.y * point2.y
dot11 = v1,v1
dot12 = v1,v2
dot13 = v1,v3
dot22 = v2,v2
dot23 = v2,v3

3rd
inverseDenominator = 1 / (dot11 * dot22 - dot12^2)
uCord = (dot22 * dot13 - dot12 * dot23) * inverseDenominator
vCord = (dot11 * dot23 - dot12 * dot13) * inverseDenominator

4th(return)
uCord >= 0
vCord >= 0
uCord + vCord < 1

<holy moly>
	std::cout << "vA " << vA.getX() << " " << vA.getY() << std::endl;
	std::cout << "vB " << vB.getX() << " " << vB.getY() << std::endl;
	std::cout << "vC " << vC.getX() << " " << vC.getY() << std::endl;
	std::cout << "dpAA " << dpAA << std::endl;
	std::cout << "dpAB " << dpAB << std::endl;
	std::cout << "dpAC " << dpAC << std::endl;
	std::cout << "dpBB " << dpBB << std::endl;
	std::cout << "dpBC " << dpBC << std::endl;
	std::cout << "invDen " << invDen << std::endl;
	std::cout << "uCord " << uCord << std::endl;
	std::cout << "vCord " << vCord << std::endl;
	
	Point vA(c.getX() - a.getX(), c.getY() - a.getY());
	Point vB(b.getX() - a.getX(), b.getY() - a.getY());
	Point vC(p.getX() - a.getX(), p.getY() - a.getY());
	Fixed dpAA(vA.getX() * vA.getX() + vA.getY() * vA.getY());
	Fixed dpAB(vA.getX() * vB.getX() + vA.getY() * vB.getY());
	Fixed dpAC(vA.getX() * vC.getX() + vA.getY() * vC.getY());
	Fixed dpBB(vB.getX() * vB.getX() + vB.getY() * vB.getY());
	Fixed dpBC(vB.getX() * vC.getX() + vB.getY() * vC.getY());
	Fixed invDen, uCord, vCord;
	invDen = 1 / (dpAA.toFloat() * dpBB.toFloat() - dpAB.toFloat() * dpAB.toFloat());
	uCord = (dpBB.toFloat() * dpAC.toFloat() - dpAB.toFloat() * dpBC.toFloat()) * invDen.toFloat();
	vCord = (dpAA.toFloat() * dpBC.toFloat() - dpAB.toFloat() * dpAC.toFloat()) * invDen.toFloat();
	
	return (uCord >= 0) && (vCord >= 0) && (uCord + vCord < 1);
*/