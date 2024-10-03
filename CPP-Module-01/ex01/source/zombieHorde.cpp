/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <gamoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:31:09 by gabe              #+#    #+#             */
/*   Updated: 2024/10/03 14:51:38 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie*	zombieHorde(int	N, std::string name)
{
	int i;
	
	i = -1;
	Zombie*	zombie_horde = new Zombie[N];
	while(++i < N)
		zombie_horde[i].set_name(name);
	return (zombie_horde);
}
