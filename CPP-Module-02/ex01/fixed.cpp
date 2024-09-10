/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:25:59 by gabe              #+#    #+#             */
/*   Updated: 2024/09/10 18:57:40 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

//	default constructor
Fixed::Fixed() : _fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point = value << Fixed::_fbits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point = roundf(value * (1 << Fixed::_fbits));
}

//	copy constructor
Fixed::Fixed(const Fixed& other) : _fixed_point(other._fixed_point)
{
	std::cout << "Copy constructor called" << std::endl;
}

//	copy assignment operator
Fixed& Fixed::operator=(const Fixed & other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixed_point = other.getRawBits();
	return *this;
}

//	destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixed_point); 
}

void	Fixed::setRawBits(int const raw) { _fixed_point = raw; }

float Fixed::toFloat(void) const
{
	return ((float)this->_fixed_point / (float)(1 << Fixed::_fbits));
}

int Fixed::toInt(void) const
{
	return (this->_fixed_point >> Fixed::_fbits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}