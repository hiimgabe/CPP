/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:03:42 by gabe              #+#    #+#             */
/*   Updated: 2024/06/05 16:51:41 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include <iostream>
#include <limits>

PhoneBook::PhoneBook(void) { this->_id = -1; }

PhoneBook::~PhoneBook(void) {}

void	PhoneBook::addContact(void)
{
	std::string			attributes[5];
	const std::string	prompt[] = {
		"First name", "Last name", "Nickname",
		"Phone nº", "Darkest secret"};
	
	this->_id = (this->_id == 8 - 1) ? -1 : this->_id; 
	for (int i = 0; i < 5; ++i)
	{
		std::cout << CLEAR << std::endl;
		std::cout << YELLOW << " _______________________________" << std::endl;
		std::cout << YELLOW << "|                               |" << std::endl;
		std::cout << YELLOW << "|          ADD CONTACT          |" << std::endl;
		std::cout << YELLOW << "|_______________________________|\n" << std::endl;
		std::cout << "Enter " << prompt[i] << " : ";
		std::getline(std::cin, attributes[i]);
		if (attributes[i].empty())
		{
			PhoneBook::printError("Can't have empty spaces.");
			return ;
		}
	}
	Contact newContact = Contact(attributes[0], attributes[1], attributes[2], attributes[3], attributes[4]);
	this->_contacts[++_id] = newContact;
	std::cout << std::endl;
	std::cout << attributes[0] << " added succesfully to phonebook." << std::endl;
	std::cout << std::endl;
	std::cout << "Press ENTER to continue." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void	PhoneBook::searchContact(void)
{
	int			i = 0;
	std::string	field;

	std::cout << CLEAR << std::endl;
	std::cout << " ___________________________________________" << std::endl;
	std::cout << "|                                           |" << std::endl;
	std::cout << "|                 PHONEBOOK                 |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	while (i < 8)
	{
		if (this->_contacts[i].getFirstName().empty())
			break ;
		std::cout << "|" << std::setw(10) << i << "|";
		field = this->_contacts[i].getFirstName();
		std::cout << std::setw(10) << Contact::formatField(field) << "|";
		field = this->_contacts[i].getLastName();
		std::cout << std::setw(10) << Contact::formatField(field) << "|";
		field = this->_contacts[i].getNickName();
		std::cout << std::setw(10) << Contact::formatField(field) << "|" << std::endl;
		//std::cout << std::endl;
		i++;
	}
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	std::cout << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void	PhoneBook::printInstructions(void)
{
	std::cout << CLEAR << std::endl;
	std::cout << YELLOW << " _______________________________" << RESET << std::endl;
	std::cout << YELLOW << "|          USER MANUAL          |" << RESET << std::endl;
	std::cout << YELLOW << "|                               |" << RESET << std::endl;
	std::cout << YELLOW << "| ADD - Add a new contact       |" << RESET << std::endl;
	std::cout << YELLOW << "| SEARCH - Look into phonebook  |" << RESET << std::endl;
	std::cout << YELLOW << "| EXIT - CLose phonebook        |" << RESET << std::endl;
	std::cout << YELLOW << "|_______________________________|" << RESET << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::printError(std::string error)
{
	std::cout << CLEAR << std::endl;
	std::cout << error << std::endl;
	std::cout << "\nPress ENTER to continue." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void	PhoneBook::_display(void) const
{
	
}