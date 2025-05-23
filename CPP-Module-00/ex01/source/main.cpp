/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:43:31 by gabe              #+#    #+#             */
/*   Updated: 2024/10/25 21:32:32 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;

	PhoneBook::printInstructions();
	while(42)
	{
		PhoneBook::printInstructions();
		std::cout << YELLOW << "Input action > ";
		if (!std::getline(std::cin, cmd, '\n'))
			return (PhoneBook::printError("EOF"), 1);
		if (cmd == "ADD")
			phonebook.addContact();
		else if (cmd == "SEARCH")
			phonebook.searchContact();
		else if (cmd == "EXIT")
			break ;
		else
		{
			PhoneBook::printError("Please input a valid action according to user manual.");
			continue ;
		}
	}
	return (0);
}
