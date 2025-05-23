/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:30:54 by gabe              #+#    #+#             */
/*   Updated: 2024/10/25 21:36:11 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <cstdlib>

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);

		Zombie(std::string name);
		void	announce(void);
		void	set_name(std::string name);
		
	private:
		std::string _name;
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);
Zombie*	zombieHorde(int N, std::string name);


#endif
