/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:39:01 by gabe              #+#    #+#             */
/*   Updated: 2024/07/23 13:35:09 by gabe             ###   ########.fr       */
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
		horde[i].announce();
	std::cout << std::endl;
	delete[] horde;
	return (0);
}
