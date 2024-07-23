/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:46:10 by gabe              #+#    #+#             */
/*   Updated: 2024/07/23 11:54:54 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;
	
	std::cout << "Addresses: " << std::endl;
	std::cout << &str << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << "\n" << std::endl;

	std::cout << "Values: " << std::endl;
	std::cout << str << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << stringREF << "\n" << std::endl;
	return (EXIT_SUCCESS);
}