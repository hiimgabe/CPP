/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:42:22 by gabe              #+#    #+#             */
/*   Updated: 2024/06/06 11:30:20 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <iomanip>
#include <limits>

#define RED "\033[38;5;196m"
#define YELLOW "\033[38;5;226m"
#define GREEN "\033[38;5;47m"
#define RESET "\033[0m"
#define CLEAR "\033[2J\033[H"

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		Contact(std::string fn, std::string ln, std::string nn,
				std::string pn, std::string ds);
				
		void display() const;
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;

		static std::string formatField(std::string field);

	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif