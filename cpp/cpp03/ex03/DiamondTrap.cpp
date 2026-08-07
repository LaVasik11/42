/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy-kankiya <georgy-kankiya@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:17:54 by gkankia           #+#    #+#             */
/*   Updated: 2025/08/27 14:35:02 by georgy-kank      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor called for " << name << std::endl;
	this->name = name;
	this->hp = 100;
	this->ep = 50;
	this->damage = 30;
}

DiamondTrap::DiamondTrap() : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    std::cout << "Default DiamondTrap constructor called" << std::endl;
    this->hp = 100;
	this->ep = 50;
	this->damage = 30;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), ScavTrap(src), FragTrap(src), name(src.name) {}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called for " << this->name << std::endl;
}

DiamondTrap &	DiamondTrap::operator=(DiamondTrap const &src)
{
	if (this != &src) {
		this->name = src.getName();
		this->hp = src.getHitPoints();
		this->ep = src.getEnergyPoints();
		this->damage = src.getAttackDamage();
	}
	return (*this);
}

void    DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->name << std::endl;
    std::cout << "DiamondTrap ClapTrap name: " << ClapTrap::name << std::endl;
}