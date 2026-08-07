/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy-kankiya <georgy-kankiya@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:09:52 by gkankia           #+#    #+#             */
/*   Updated: 2025/08/17 21:00:04 by georgy-kank      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    ClapTrap    hero1("Name1");
    ScavTrap    hero2("Name2");
    FragTrap    hero3("Name3");

    hero2.attack("enemy1");
    hero1.attack("enemy1");
    hero3.attack("enemy4");
    hero1.beRepaired(10);
    hero1.beRepaired(10);
    hero1.beRepaired(10);
    hero1.beRepaired(10);
    hero1.beRepaired(10);
    hero1.beRepaired(10);
    hero1.beRepaired(10);
    hero1.beRepaired(10);
    hero1.beRepaired(10);
    hero1.beRepaired(10);
    hero1.beRepaired(10);
    hero2.takeDamage(10);
    hero2.attack("enemy2");
    hero1.attack("enemy1");
    hero1.beRepaired(3);
    hero2.beRepaired(20);
    hero3.attack("enemy4");
    hero3.attack("enemy4");
    hero3.attack("enemy4");
    hero3.takeDamage(100);
    hero3.attack("enemy4");
    
    std::cout << "\n-----------------------------------------\n";

    DiamondTrap diamond("diamond");
    
    diamond.attack("enemy1");
    diamond.takeDamage(10);
    diamond.beRepaired(30);
    diamond.attack("enemy2");
    diamond.attack("enemy3");
    diamond.takeDamage(120);
    diamond.beRepaired(10);
    diamond.attack("enemy1");

    diamond.whoAmI();
    return (0);
}