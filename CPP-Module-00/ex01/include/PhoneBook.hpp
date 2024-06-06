/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:37:29 by gabe              #+#    #+#             */
/*   Updated: 2024/06/06 11:16:13 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <limits>

#define RED "\033[38;5;196m"
#define YELLOW "\033[38;5;226m"
#define GREEN "\033[38;5;47m"
#define RESET "\033[0m"
#define CLEAR "\033[2J\033[H"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		
		void	addContact(void);
		void	searchContact(void);
		
		static void	printInstructions(void);
		static void	printError(std::string error);
	
	private:
		Contact _contacts[8];
		int		_id;
		void	_display(void) const;
};

#endif