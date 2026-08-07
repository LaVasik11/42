/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:17:01 by gkankia           #+#    #+#             */
/*   Updated: 2026/03/17 20:51:43 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hp(10), ep(10), damage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hp(10), ep(10), damage(0)
{
    std::cout << "Constructor called for " << name << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
    *this = src;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &src)
{
    if (this != &src)
    {
        this->hp = src.hp;
        this->ep = src.ep;
        this->damage = src.damage;
    }
    return (*this);
}

std::string ClapTrap::getName() const
{
    return (this->name);
}

int	ClapTrap::getHitPoints() const
{
	return (this->hp);
}

int	ClapTrap::getEnergyPoints() const
{
	return (this->ep);
}

int	ClapTrap::getAttackDamage() const
{
	return (this->damage);
}

void    ClapTrap::setName(std::string name)
{
    this->name = name;
}

void	ClapTrap::setHitPoints(int hp)
{
	this->hp = hp;
}

void	ClapTrap::setEnergyPoints(int ep)
{
	this->ep = ep;
}

void	ClapTrap::setAttackDamage(int damage)
{
	this->damage = damage;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hp > 0)
    {
        if (this->ep > 0)
        {
            std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
            this->ep--;
        }
        else
            std::cout << "ClapTrap " << this->name << " doesn't have enough energy points." << std::endl;
        std::cout << "ClapTrap " << this->name << " has " << this->ep << " energy points." << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hp > 0)
    {
        std::cout << "ClapTrap " << this->name << " take " << amount << " damage!" << std::endl;
        if (amount > (unsigned)this->hp)
        {
            this->hp = 0;
            std::cout << this->name << " is dead!" << std::endl;
        }
        else
            this->hp -= amount;
        std::cout << "ClapTrap " << this->name << " has " << this->hp << " hp." << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hp > 0)
    {
        if (this->ep > 0)
        {    
            std::cout << "ClapTrap " << this->name << " repaired " << amount << " hp!" << std::endl;
            this->ep--;
            this->hp += amount;
        }
        else
            std::cout << "ClapTrap " << this->name << " doesn't have enough energy points." << std::endl;
        std::cout << "ClapTrap " << this->name << " has " << this->ep << " energy points." << std::endl;
        std::cout << "ClapTrap " << this->name << " has " << this->hp << " hit points." << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
}