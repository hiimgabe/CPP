/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:17:07 by gabe              #+#    #+#             */
/*   Updated: 2024/09/06 15:45:39 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <ostream>

class Fixed
{
public:
	//	default constructor
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	//	copy constructor
	Fixed(const Fixed &other);
	//	copy assignment operator
	Fixed &operator=(const Fixed &other);
	//	destructor
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int	toInt(void) const;

private:
	int _fixed_point;
	static const int _fbits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif