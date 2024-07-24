/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:17:24 by gabe              #+#    #+#             */
/*   Updated: 2024/07/24 15:48:44 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <unistd.h>

int	main(int argc, char **argv)
{
	Harl	harl;
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i;
	
	if (argc != 2)
		return(write(2, "./harlfilter <level-complain>\n", 31), EXIT_FAILURE);
	for (i = 0; i < 4; i++)
		if (levels[i] == argv[1])
			break ;		
	switch (i)
	{
	case DEBUG:
		std::cout << "[ DEBUG ]" << std::endl;
		harl.complain("DEBUG");
		break;
	case INFO:
		std::cout << "[ INFO ]" << std::endl;
		harl.complain("INFO");
		break;
	case WARNING:
		std::cout << "[ WARNING ]" << std::endl;
		harl.complain("WARNING");
		break;
	case ERROR:
		std::cout << "[ ERROR ]" << std::endl;
		harl.complain("ERROR");
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
	return (EXIT_SUCCESS);
}