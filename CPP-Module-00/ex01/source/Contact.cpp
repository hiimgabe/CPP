/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:39:39 by gabe              #+#    #+#             */
/*   Updated: 2024/06/06 12:01:55 by gabe             ###   ########.fr       */
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

void Contact::display(void) const 
{
	std::cout << CLEAR;
	std::cout << std::endl;
	std::cout << YELLOW << " ________________________________________" << std::endl;
	std::cout << "| " << std::setw(40) <<"|" << std::endl;
	std::cout << "| First name : " << this->_firstName << std::setw(27 - this->_firstName.length()) <<"|" << std::endl;
	std::cout << "| Last name  : " << this->_lastName << std::setw(27 - this->_lastName.length()) <<"|" << std::endl;
	std::cout << "| Nickname   : " << this->_nickName << std::setw(27 - this->_nickName.length()) <<"|" << std::endl;
	std::cout << "| Phone nº   : " << this->_phoneNumber << std::setw(27 - this->_phoneNumber.length()) <<"|" << std::endl;
	std::cout << "|________________________________________|" << std::endl;
	std::cout << std::endl;
	std::cout << "Darkest secret : " << this->_darkestSecret << std::endl;
	std::cout << std::endl;
	std::cout << "Press ENTER to continue." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string Contact::getFirstName(void) const { return (this->_firstName); }

std::string Contact::getLastName(void) const { return (this->_lastName); }

std::string Contact::getNickName(void) const { return (this->_nickName); }