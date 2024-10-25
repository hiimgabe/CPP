/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:39:01 by gabe              #+#    #+#             */
/*   Updated: 2024/10/25 21:35:17 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int	main(int argc, char **argv)
{
	int	i, size;
	if (argc != 3)
		return (std::cout << "Usage: " << argv[0] << " <size> <hordeName>" << std::endl, 0);
	i = -1;
	size = std::atoi(argv[1]);
	Zombie*	horde = zombieHorde(size ,argv[2]);
	while (++i < size)
	{
		std::cout << i + 1 << " ";
		horde[i].announce();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	delete[] horde;
	return (0);
}
