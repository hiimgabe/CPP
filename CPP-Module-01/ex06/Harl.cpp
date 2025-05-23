/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:53:08 by gabe              #+#    #+#             */
/*   Updated: 2024/07/24 15:41:27 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
			  << " I really do!"
			  << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!"
			  << " If you did, I wouldn’t be asking for more!"
			  << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free."
			  << " I’ve been coming for years whereas you started working here since last month."
			  << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}

void	Harl::complain(std::string level)
{
	//	Defining Pointers to member functions(PMF)
	void (Harl::*funcPTR[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	//	Possible Levels
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	//	Checking which level was called through PMF
	for (int i = 0; i < 4; i++)
		if (levels[i] == level)
			(this->*funcPTR[i])();
}