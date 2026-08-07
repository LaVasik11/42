/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:09:52 by gkankia           #+#    #+#             */
/*   Updated: 2025/08/05 16:52:47 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
    return (0);
}