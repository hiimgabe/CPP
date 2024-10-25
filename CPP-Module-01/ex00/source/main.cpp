/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:39:01 by gabe              #+#    #+#             */
/*   Updated: 2024/10/25 12:06:16 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int	main(int argc, char **argv)
{
	int			i;
	std::string	zombie[10];

	if (argc != 4)
		return (std::cout << "Usage: " << argv[0] << " <zombie1> <zombie2> <zombie3>" << std::endl, 1);
	i = 1;
	while(1)
	{
		if (argv[i] && i < 11)
			zombie[i] = argv[i];
		else if (!argv[i] || i >= 11)
			break ;
		std::cout << zombie[i] << " assigned." << std::endl;
		i++;
	}
	std::cout << std::endl;
	Zombie* z1 = newZombie(zombie[1]);
	z1->announce();
	std::cout << "Zombie allocated on HEAP.\n" << std::endl;
	Zombie z2 = Zombie(zombie[2]);
	z2.announce();
	std::cout << "Zombie allocated on STACK.\n" << std::endl;
	randomChump(zombie[3]);
	delete z1;
	return (0);
}
