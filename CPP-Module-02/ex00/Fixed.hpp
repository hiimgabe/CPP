/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:17:07 by gabe              #+#    #+#             */
/*   Updated: 2024/10/25 21:47:54 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
public:
	//	default constructor
	Fixed();
	//	copy constructor
	Fixed(const Fixed &other);
	//	copy assignment operator
	Fixed &operator=(const Fixed &other);
	//	destructor
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _fixed_point;
	static const int _fbits = 8;
};

#endif