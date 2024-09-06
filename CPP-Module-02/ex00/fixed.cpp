/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:25:59 by gabe              #+#    #+#             */
/*   Updated: 2024/09/06 11:24:35 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"
#include <iostream>

//	default constructor
Fixed::Fixed() : _fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//	copy constructor
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
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