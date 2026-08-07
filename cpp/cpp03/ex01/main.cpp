/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:09:52 by gkankia           #+#    #+#             */
/*   Updated: 2025/08/05 16:46:16 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap    hero1("Name1");
    ScavTrap    hero2("Name2");

    hero2.attack("enemy1");
    hero1.attack("enemy1");
    hero2.takeDamage(10);
    hero1.takeDamage(10);
    hero2.attack("enemy2");
    hero1.attack("enemy1");
    hero1.beRepaired(3);
    hero2.beRepaired(20);    

    return (0);
}