/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:39:39 by gabe              #+#    #+#             */
/*   Updated: 2024/06/05 16:43:47 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

Contact::Contact(void) : 
	_firstName(""), _lastName(""), _nickName(""),
	_phoneNumber(""), _darkestSecret("")
{
}

Contact::Contact(std::string fn, std::string ln, std::string nn,
				 std::string pn, std::string ds)
	: _firstName(fn), _lastName(ln), _nickName(nn),
	  _phoneNumber(pn), _darkestSecret(ds)
{
} 

Contact::~Contact(void) {}

std::string Contact::formatField(std::string field)
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

std::string Contact::getFirstName(void) const { return (this->_firstName); }

std::string Contact::getLastName(void) const { return (this->_lastName); }

std::string Contact::getNickName(void) const { return (this->_nickName); }