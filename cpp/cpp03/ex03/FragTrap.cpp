/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy-kankiya <georgy-kankiya@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:55:24 by gkankia           #+#    #+#             */
/*   Updated: 2025/08/27 14:35:02 by georgy-kank      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called for " << name << std::endl;
	this->hp = 100;
	this->ep = 100;
	this->damage = 30;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src.getName())
{
	*this = src;
}

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->hp = 100;
	this->ep = 100;
	this->damage = 30;
}


FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called for " << this->name << std::endl;
}

FragTrap &	FragTrap::operator=(FragTrap const &src) {
	if (this != &src) {
		this->name = src.getName();
		this->hp = src.getHitPoints();
		this->ep = src.getEnergyPoints();
		this->damage = src.getAttackDamage();
	}
	return *this;
}

void	FragTrap::attack(const std::string &target)
{
	if (this->hp > 0)
    {
        if (this->ep > 0)
        {
            std::cout << "FragTrap " << this->name << " deals " << this->damage << " damage to the " << target << std::endl;
            this->ep--;
        }
        else
            std::cout << "ClapTrap " << this->name << " doesn't have enough energy points." << std::endl;
        std::cout << "ClapTrap " << this->name << " has " << this->ep << " energy points." << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << ": High five!" << std::endl;
}
