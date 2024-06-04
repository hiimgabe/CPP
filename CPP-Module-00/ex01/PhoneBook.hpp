/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:37:29 by gabe              #+#    #+#             */
/*   Updated: 2024/06/04 15:49:10 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>


class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		
		void	addContact(void);
		void	searchContact(void);
		
		static void	printManual(void);
	
	private:
		Contact _contacts[8];
		int		_id;
		void	_display(void) const;
};

#endif