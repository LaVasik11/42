/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy-kankiya <georgy-kankiya@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:22:45 by gkankia           #+#    #+#             */
/*   Updated: 2025/08/27 14:35:02 by georgy-kank      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called for " << name << std::endl;
	this->hp = 100;
	this->ep = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src.getName())
{
	*this = src;
}

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
    this->hp = 100;
    this->ep = 50;
    this->damage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called for " << this->name << std::endl;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const &src) {
	if (this != &src) {
		this->name = src.getName();
		this->hp = src.getHitPoints();
		this->ep = src.getEnergyPoints();
		this->damage = src.getAttackDamage();
	}
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->hp > 0)
    {
        if (this->ep > 0)
        {
            std::cout << "ScavTrap " << this->name << " go for broke " << target << " causing him " << this->damage << " attack damage" << std::endl;
            this->ep--;
        }
        else
            std::cout << "ClapTrap " << this->name << " doesn't have enough energy points." << std::endl;
        std::cout << "ClapTrap " << this->name << " has " << this->ep << " energy points." << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gatekeeper mode." << std::endl;
}