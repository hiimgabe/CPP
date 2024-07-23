/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:37:20 by gabe              #+#    #+#             */
/*   Updated: 2024/07/23 13:34:13 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon(void) { std::cout << "Weapon desctructed." << std::endl; }

std::string Weapon::getType(void) const { return (this->_type); }

void	Weapon::setType(std::string newType) { this->_type = newType; }
