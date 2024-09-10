/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:17:07 by gabe              #+#    #+#             */
/*   Updated: 2024/09/10 11:29:23 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <ostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator>(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	static Fixed max(Fixed &a, Fixed &b);
	static Fixed max(const Fixed &a, const Fixed &b);
	static Fixed min(Fixed &a, Fixed &b);
	static Fixed min(const Fixed &a, const Fixed &b);
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